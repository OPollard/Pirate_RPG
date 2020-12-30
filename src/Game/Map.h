
#pragma once

#include "Tile.h"

struct Player;

struct Map
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Map();
	Map(sf::RenderWindow& window, Resources& r, sf::View& mapView);
	~Map();

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, Player& player, sf::View& mapView, Resources& r);
	void Render(sf::RenderWindow& window, Player& player, sf::View& mapView);

	void UpdateView(sf::RenderWindow& window, Player& player, sf::View& mapView);
	void UpdateTiles(Resources& r);



	// ______ VARIABLES ______ \\

	std::vector < std::vector <std::unique_ptr<Tile>>> map;

	sf::Clock clock;

	uint32_t gridUnit = 32;
	uint32_t DrawOverlap = 7; // previous = 7

	uint32_t mapXSize = 100;
	uint32_t mapYSize = 100;
	int32_t LeftEdge = 0;
	int32_t RightEdge = 0;
	int32_t TopEdge = 0;
	int32_t BottomEdge = 0;

};

