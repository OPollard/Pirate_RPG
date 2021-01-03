

#include <sstream>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

#include "..\Entities\NPC.h"

#include "..\Modules\Collision.h"
#include "..\Modules\Math.h"

#include "GUI.h"
#include "Map.h"

#include "World.h"


World::World(sf::RenderWindow& window, Player& player)
{

	// ensure no missing files
	if (!r.LoadResources())
	{
		std::cout << "Error Loading Resources! " << std::endl;
	}

	// init script
	InitialiseLevel(window, player);
	
}

void World::InitialiseLevel(sf::RenderWindow& window, Player& player)
{

	// init player
	player.Initialise(window, r);

	// init NPC's
	NPCs.emplace_back(std::unique_ptr<NPC>(new NPC(window, r, "Goblin", true, {790.0f, 128.0f }, 2.0f, WorldDeg(-145.0f))));
	NPCs.emplace_back(std::unique_ptr<NPC>(new NPC(window, r, "Danger Boss", true, { 288.0f,160.0f }, 1.0f, WorldDeg(175.0f))));

	// init GUI
	gui = std::unique_ptr<GUI>(new GUI(window, r));


	// init map
	map = std::unique_ptr<Map>(new Map(window, r, mapView));

	// init music
	r.music.setLoop(true);
	r.music.play();
}

// game loop
void World::UpdateAndRender(sf::RenderWindow& window, Player& player)
{
	Performance::Start();
	UpdateLevel(window, player);

	UpdateEntities(window, player);
	Performance::Lap("Entities");

	UpdateCollisions(window, player);
	Performance::Lap("Collisions");

	UpdateGUI(window, player);	
	Performance::Stop("GUI");

	Performance::PrintTimeLog();

}

// map and environment
void World::UpdateLevel(sf::RenderWindow& window, Player& player)
{
	// update map (tiles and props)
	map->Update(window, player, mapView, r, Level::mousePosMap);
	Performance::Lap("Update Map");

	map->Render(window, player, mapView);
	Performance::Lap("Render Map");

}

// all players and bots
void World::UpdateEntities(sf::RenderWindow& window, Player& player)
{

	// update NPC's
	for (auto& n : NPCs)
	{
		n->Update(window, r);
	}

	// update player
	player.Update(window, r);
}

// determine collisions
void World::UpdateCollisions(sf::RenderWindow& window, Player& player)
{
	Consolidate(NPCs, player, *map);
}

void World::UpdateGUI(sf::RenderWindow& window, Player& player)
{
	// focus view
	window.setView(window.getDefaultView());

	// mouse
	Level::UpdateMousePositions(window, *map, player);

	// TEMP
	if (player.movement.GetXCoord() > 1450.0f && player.movement.GetXCoord() < 1500.0f)
	{
		
		gui->CreateNotification(window, r, std::string("You found me"), 1);
	}
	//END TEMP

	gui->Update(window, Level::mousePosView);

}

void World::UpdateView(sf::RenderWindow& window, const sf::Event& event)
{
	// update view
	mapView.setSize((float)event.size.width, (float)event.size.height);

	window.setView(mapView);
}

// manage event handling
void World::UpdateEvents(sf::RenderWindow& window, Player& player, const sf::Event& event)
{
	// update player
	player.KeyInput(window, r, event);
}

void World::CloseLevel()
{
	map->map.clear();
	std::cout << "World Cleaned Up" << std::endl;
}


World::~World()
{
}