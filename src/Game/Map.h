
#pragma once

#include "Tile.h"

struct Player;
struct Prop;

struct Map
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Map();
	Map(sf::RenderWindow& window, Resources& r, sf::View& mapView);
	~Map();

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, Player& player, sf::View& mapView, Resources& r, sf::Vector2i mousePos);
	void Render(sf::RenderWindow& window, Player& player, sf::View& mapView);

	void UpdateView(sf::RenderWindow& window, Player& player, sf::View& mapView);
	void UpdateTiles(Resources& r);
	void UpdateProps(sf::RenderWindow& window, Resources& r);

	void CheckMouseLocation(sf::Vector2i mousePos);



	// ______ VARIABLES ______ \\

	std::vector < std::vector <std::unique_ptr<Tile>>> map;

	std::vector <Prop>  props;

	sf::Clock clock;

	uint32_t gridUnit = 32;
	uint32_t DrawOverlap = 7; 

	uint32_t mapXSize = 100;
	uint32_t mapYSize = 100;
	int32_t LeftEdge = 0;
	int32_t RightEdge = 0;
	int32_t TopEdge = 0;
	int32_t BottomEdge = 0;

};

