
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

void Level::UpdateView(sf::RenderWindow& window, sf::Event& event)
{

}

void Level::UpdateMousePositions(sf::RenderWindow& window)
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(window);
	mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
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
