

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
	// Ensure no missing files
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
	NPCs.emplace_back(std::unique_ptr<NPC>(new NPC(window, r, "Goblin", true, { 300.0f,600.0f }, 3.0f, WorldDeg(270.0f))));
	NPCs.emplace_back(std::unique_ptr<NPC>(new NPC(window, r, "Danger Boss", true, { 400.0f,200.0f }, 1.0f, WorldDeg(180.0f))));

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

	UpdateLevel(window, player);

	UpdateEntities(window, player);
#ifdef PERF 
	perf.Lap("Entities");
#endif 
	UpdateCollisions(window, player);
#ifdef PERF 
	perf.Lap("Collisions");
#endif 
	UpdateGUI(window, player);	
#ifdef PERF 
	perf.Stop("GUI");
	perf.PrintTimeLog();
#endif 

}

// map and environment
void World::UpdateLevel(sf::RenderWindow& window, Player& player)
{
	// update map
#ifdef PERF 
	perf.Start();
	map->Update(window, player, mapView, r);
	perf.Lap("Update Map");
#endif 
#ifdef PERF 
	map->Render(window, player, mapView);
	perf.Lap("Render Map");

#endif 
}

// all players and bots
void World::UpdateEntities(sf::RenderWindow& window, Player& player)
{

	// update player
	player.Update(window, r);

	// update NPC's
	for (auto& n : NPCs)
	{
		n->Update(window, r);
	}

}

// determine collisions
void World::UpdateCollisions(sf::RenderWindow& window, Player& player)
{

	Consolidate(NPCs, player);
}

void World::UpdateGUI(sf::RenderWindow& window, Player& player)
{
	// focus view
	window.setView(window.getDefaultView());

	Level::UpdateMousePositions(window);


	if (player.movement.xCoord > 1450 && player.movement.xCoord < 1500)
	{
		
		gui->CreateNotification(window, r, std::string("You found me"), 1);
	}
	
	gui->Update(window, Level::mousePosView);

}

// adjust view to new window
void World::UpdateView(sf::RenderWindow& window, sf::Event& event)
{
	mapView.setSize((float)event.size.width, (float)event.size.height);

	window.setView(mapView);
}

void World::CloseLevel()
{
	map->map.clear();
	std::cout << "World Cleaned Up" << std::endl;
}


World::~World()
{
}