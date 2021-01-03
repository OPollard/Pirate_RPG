
#pragma once

#include "Tile.h"

struct Player;
struct Prop;

struct Map
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Map();
	Map(sf::RenderWindow& window, const Resources& r, sf::View& mapView);
	~Map();

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, Player& player, sf::View& mapView, const Resources& r, const sf::Vector2i& mousePos);
	void Render(sf::RenderWindow& window, Player& player, sf::View& mapView);

	void UpdateView(sf::RenderWindow& window, Player& player, sf::View& mapView);
	void UpdateTiles(const Resources& r);
	void UpdateProps(sf::RenderWindow& window, const Resources& r);

	void CheckMouseLocation(const sf::Vector2i& mousePos);



	// ______ VARIABLES ______ \\

	std::vector < std::vector <std::unique_ptr<Tile>>> map;

	std::vector <Prop>  props;

	sf::Clock clock;

	const uint32_t gridUnit = 32;
	const uint32_t DrawOverlap = 7; 

	const uint32_t mapXSize = 100;
	const uint32_t mapYSize = 100;

	int32_t LeftEdge = 0;
	int32_t RightEdge = 0;
	int32_t TopEdge = 0;
	int32_t BottomEdge = 0;

};

