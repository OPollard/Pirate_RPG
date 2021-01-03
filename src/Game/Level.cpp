
#include "Map.h"
#include "..\Entities\Player.h"
#include "Level.h"

Level::Level()
{
}

void Level::InitialiseLevel(sf::RenderWindow& window, Player& player)
{

}


void Level::UpdateAndRender(sf::RenderWindow& window, Player& player)
{
}

void Level::UpdateEntities(sf::RenderWindow& window, Player& player)
{
}

void Level::UpdateCollisions(sf::RenderWindow& window, Player& player)
{

}

void Level::UpdateLevel(sf::RenderWindow& window, Player& player)
{
}

void Level::UpdateGUI(sf::RenderWindow& window, Player& player)
{

}

void Level::UpdateView(sf::RenderWindow& window, const sf::Event& event)
{

}

void Level::UpdateEvents(sf::RenderWindow& window, Player& player, const sf::Event& event)
{

}

void Level::UpdateMousePositions(sf::RenderWindow& window, const Map& map, Player& player)
{
	// window positions
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	
	// sync to player position
	mousePosMap.x = player.movement.GetXPos();
	mousePosMap.y = player.movement.GetYPos();

	// position from centre of screen offset
	const float xOffset = (mousePosView.x) - (window.getView().getSize().x / 2.0f);
	const float yOffset = (mousePosView.y) - (window.getView().getSize().y / 2.0f);

	// convert to grid units
	const float xPosOffset = xOffset / static_cast<float>(map.gridUnit);
	const float yPosOffset = yOffset / static_cast<float>(map.gridUnit);

	// calculate mouse world position
	mousePosMap.x = static_cast<int32_t>(mousePosMap.x + xPosOffset);
	mousePosMap.y = static_cast<int32_t>(mousePosMap.y + yPosOffset);
}

void Level::CheckEventActions(const sf::Event& e)
{
}


void Level::CloseLevel()
{
}

Level::~Level()
{
	
}
