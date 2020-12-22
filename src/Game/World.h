#pragma once

#include "Level.h"
#include "GUI.h"
#include "Map.h"

#include "..\Entities\NPC.h"

struct World : public Level
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	World(sf::RenderWindow& window, Player& player);
	~World() override;
	void InitialiseLevel(sf::RenderWindow& window, Player& player) override;


	// ______ FUNCTIONS ______ \\
		
	void UpdateAndRender(sf::RenderWindow& window, Player& player) override;
	void UpdateEntities(sf::RenderWindow& window, Player& player) override;
	void UpdateCollisions(sf::RenderWindow& window, Player& player) override;
	void UpdateLevel(sf::RenderWindow& window, Player& player) override;
	void UpdateGUI(sf::RenderWindow& window, Player& player) override;
	void UpdateView(sf::RenderWindow& window, sf::Event& event) override;

	void CloseLevel() override;


	// ______ VARIABLES ______ \\

		
	Resources r;

	std::unique_ptr<Map> map;

	sf::View mapView;

	std::vector<std::unique_ptr<Entity>> NPCs;

	std::unique_ptr<GUI> gui;

};
