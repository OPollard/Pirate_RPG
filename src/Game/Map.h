
#pragma once

#include "Tile.h"
#include "..\Entities\Player.h"


struct Map
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

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

	uint32_t gridUnit = 64;
	uint32_t DrawOverlap = 7; // previous = 7

	uint32_t mapXSize = 40;
	uint32_t mapYSize = 40;
	int32_t LeftEdge = 0;
	int32_t RightEdge = 0;
	int32_t TopEdge = 0;
	int32_t BottomEdge = 0;

};

