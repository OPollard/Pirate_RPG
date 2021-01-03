#pragma once

#include "SFML/Graphics.hpp"

struct Player;
struct Map;

struct Level
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Level();
	virtual void InitialiseLevel(sf::RenderWindow& window, Player& player);
	virtual ~Level();


	// ______ FUNCTIONS ______ \\

	virtual void UpdateAndRender(sf::RenderWindow& window, Player& player);
	virtual void UpdateEntities(sf::RenderWindow& window, Player& player);
	virtual void UpdateCollisions(sf::RenderWindow& window, Player& player);
	virtual void UpdateLevel(sf::RenderWindow& window, Player& player);
	virtual void UpdateGUI(sf::RenderWindow& window, Player& player);
	virtual void UpdateView(sf::RenderWindow& window, sf::Event& event);
	virtual void UpdateEvents(sf::RenderWindow& window, Player& player, sf::Event& event);
	void UpdateMousePositions(sf::RenderWindow& window, Map& map, Player& player);

	virtual void CheckEventActions(sf::Event& e);
	virtual void CloseLevel();


	// ______ VARIABLES ______ \\

	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	sf::Vector2i mousePosMap;

};

