
#include "Resources.h"

#include "..\Entities\Player.h"
#include "..\Entities\Prop.h"

#include "Map.h"

//temp
#include <iostream>

Map::Map()
{

}

Map::Map(sf::RenderWindow& window, Resources& r, sf::View& mapView)
{
	
	// init view
	mapView = sf::View();
	mapView.setSize(window.getView().getSize().x, window.getView().getSize().y);

	// init clock
	clock.restart();
	
	// calibrate map grid to tile size
	gridUnit = 32;

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

	// fill map with world props
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tl, 38, 38));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tr, 39, 38));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_bl, 38, 39));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_br, 39, 39));

	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tl, 40, 38));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_tr, 41, 38));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_bl, 40, 39));
	props.push_back(Prop("Tree", r.objSheet, r.tree_lightgreen_br, 41, 39));

}

// main map loop
void Map::Update(sf::RenderWindow& window, Player& player, sf::View& mapView, Resources& r, sf::Vector2i mousePos)
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

void Map::UpdateProps(sf::RenderWindow& window, Resources& r)
{
	// update props in world
	for (auto& p : props)
	{
		p.Update(window, r);
	}

}

void Map::CheckMouseLocation(sf::Vector2i mousePos)
{

	// prop
	for (auto& p : props)
	{
		if (p.movement.GetPos() == mousePos)
		{
			std::cout << p.name << std::endl;
		}
	}

	

	// prop
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
			window.draw(map[i][j]->sprite);
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