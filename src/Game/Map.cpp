
#include "Resources.h"

#include "..\Entities\Player.h"
#include "..\Entities\Prop.h"
#include "..\Modules\Generator.h"

#include "Map.h"

//temp
#include <iostream>

Map::Map()
{

}

Map::Map(sf::RenderWindow& window, const Resources& r, sf::View& mapView)
{
	
	// init view
	mapView = sf::View();
	mapView.setSize(window.getView().getSize().x, window.getView().getSize().y);

	// init clock
	clock.restart();

	// fill map capacity
	map.resize(mapXSize);
	for (auto& v : map)
	{
		v.resize(mapYSize);
	}
	
	// TEMP FOR LOOPS
	// fill map with background ocean
	for (uint32_t x = 0; x < map.size(); x++)
	{
		for (uint32_t y = 0; y < map[x].size(); y++)
		{
			map[x][y] = std::unique_ptr<Tile>(new Tile(r.ocean, r.spriteRect, false, true, true));
			// align sprite to coordinates
			map[x][y]->sprite.setPosition(sf::Vector2f(static_cast<float>(gridUnit * x), static_cast<float>(gridUnit * y)));
		}
	}
	// END TEMP

	// fill map from tile data in file
	Generator::ExtractMapData(r.mapDataFilePath, map, gridUnit, r);


	// prop creation
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tl, 5, 4));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tr, 6, 4));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_bl, 5, 5));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_br, 6, 5));

	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tl, 15, 8));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tr, 16, 8));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_bl, 15, 9));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_br, 16, 9));

}

// main map loop
void Map::Update(sf::RenderWindow& window, Player& player, sf::View& mapView, const Resources& r, const sf::Vector2i& mousePos)
{
	UpdateView(window, player, mapView);

	UpdateTiles(r);
	
	CheckMouseLocation(mousePos);

	UpdateProps(window, r);
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

void Map::UpdateTiles(const Resources& r)
{
	// update tiles within view
	for (int32_t i = LeftEdge; i < RightEdge; ++i)
	{
		for (int32_t j = TopEdge; j < BottomEdge; ++j)
		{
			if (map[i][j])
			{
				map[i][j]->Update(clock, r);
			}
		}
	}
}

void Map::UpdateProps(sf::RenderWindow& window, const Resources& r)
{
	// update props in world
	for (auto& p : props)
	{
		p.Update(window, r);
	}

}

void Map::CheckMouseLocation(const sf::Vector2i& mousePos)
{
	// prop
	for (auto& p : props)
	{
		if (p.movement.GetPos() == mousePos)
		{
			std::cout << p.name << std::endl;
		}
	}

}


void Map::Render(sf::RenderWindow& window, Player& player, sf::View& mapView)
{
	// viewable map area
	window.setView(mapView);

	// draw tiles
	for (int32_t i = LeftEdge; i < RightEdge; ++i)
	{
		for (int32_t j = TopEdge; j < BottomEdge; ++j)
		{
			if (map[i][j])
			{
				window.draw(map[i][j]->sprite);
			}
		}
	}

	// draw props
	for (const auto& p : props)
	{
		window.draw(p.sprite);
	}
}

Map::~Map()
{
}