
#include "Map.h"
#include "..\Entities\Player.h"
#include "Level.h"

//temp 
#include <iostream>

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

void Level::UpdateView(sf::RenderWindow& window, sf::Event& event)
{

}

void Level::UpdateEvents(sf::RenderWindow& window, Player& player, sf::Event& event)
{

}

void Level::UpdateMousePositions(sf::RenderWindow& window, Map& map, Player& player)
{
	// window positions
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	
	// sync to player character position
	mousePosMap.x = player.movement.GetXPos();
	mousePosMap.y = player.movement.GetYPos();

	// position from centre of screen offset
	float xOffset = (mousePosView.x - (window.getView().getSize().x / 2.0f));
	float yOffset = (mousePosView.y - (window.getView().getSize().y / 2.0f));

	// convert to grid units
	int32_t xPosOffset = static_cast<int32_t>(xOffset / 32.0f);
	int32_t yPosOffset = static_cast<int32_t>(yOffset / 32.0f);

	// mouse world position
	mousePosMap.x += xPosOffset;
	mousePosMap.y += yPosOffset;


	//temp
	std::cout << mousePosMap.x << ", " << mousePosMap.y << std::endl;
	
}

void Level::CheckEventActions(sf::Event& e)
{
}


void Level::CloseLevel()
{
}

Level::~Level()
{
	
}
