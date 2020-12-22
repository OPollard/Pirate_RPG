
#include "Map.h"
#include "..\Entities\Player.h"

Map::Map(sf::RenderWindow& window, Resources& r, sf::View& mapView)
{
	
	// init view
	mapView = sf::View();
	mapView.setSize(window.getView().getSize().x, window.getView().getSize().y);

	// init clock
	clock.restart();
	
	// calibrate map grid to tile size
	gridUnit = 64;

	// fill map with tiles
	for (uint32_t x = 0; x < mapXSize; ++x)
	{
		map.emplace_back(std::vector<std::unique_ptr<Tile>>());

		for (uint32_t y = 0; y < mapYSize; ++y)
		{
			
			map[x].emplace_back(std::unique_ptr<Tile>(new Tile(r.ocean)));
		
			map[x][y]->sprite.setPosition(sf::Vector2f(static_cast<float>(gridUnit * x), static_cast<float>(gridUnit * y)));

		}
	}

}

// main map loop
void Map::Update(sf::RenderWindow& window, Player& player, sf::View& mapView, Resources& r)
{
	UpdateView(window, player, mapView);
	UpdateTiles(r);

}

// center view overhead player
void Map::UpdateView(sf::RenderWindow& window, Player& player, sf::View& mapView)
{
	// keeps camera steady
	if (player.movement.enableMovement)
	{
		mapView.setCenter(player.sprite.getPosition().x, player.sprite.getPosition().y);
	}

	// get edges of view 
	LeftEdge = static_cast<int32_t>(player.sprite.getPosition().x / gridUnit) - static_cast<int32_t>((window.getView().getSize().x / 2 / gridUnit)) - DrawOverlap;
	RightEdge = static_cast<int32_t>(player.sprite.getPosition().x / gridUnit) + static_cast<int32_t>((window.getView().getSize().x / 2 / gridUnit)) + DrawOverlap ;
	TopEdge = static_cast<int32_t>(player.sprite.getPosition().y / gridUnit) - static_cast<int32_t>((window.getView().getSize().y / 2 / gridUnit)) - DrawOverlap;
	BottomEdge = static_cast<int32_t>(player.sprite.getPosition().y / gridUnit) + static_cast<int32_t>((window.getView().getSize().y / 2 / gridUnit)) + DrawOverlap ;

	// guard against null dereferencing
	if (LeftEdge < 0) LeftEdge = 0;
	if (LeftEdge > (int32_t)mapXSize) LeftEdge = mapXSize - 1;
	if (RightEdge < 0) RightEdge = 0;
	if (RightEdge > (int32_t)mapXSize) RightEdge = mapXSize - 1;
	if (TopEdge < 0) TopEdge = 0;
	if (TopEdge > (int32_t)mapYSize) TopEdge = mapYSize - 1;
	if (BottomEdge < 0) BottomEdge = 0;
	if (BottomEdge > (int32_t)mapYSize) BottomEdge = mapYSize - 1;
}

void Map::UpdateTiles(Resources& r)
{
	// update tiles within view
	for (int32_t i = LeftEdge; i < RightEdge; ++i)
	{
		for (int32_t j = TopEdge; j < BottomEdge; ++j)
		{
			map[i][j]->Update(clock, r);
		}
	}
}


void Map::Render(sf::RenderWindow& window, Player& player, sf::View& mapView)
{
	// viewable map area
	window.setView(mapView);

	for (int32_t i = LeftEdge; i < RightEdge; ++i)
	{
		for (int32_t j = TopEdge; j < BottomEdge; ++j)
		{
			window.draw(map[i][j]->sprite);
		}
	}
}

Map::~Map()
{
}