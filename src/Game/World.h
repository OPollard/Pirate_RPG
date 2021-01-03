#pragma once


#include "..\Modules\Performance.h"
#include "Resources.h"
#include "Level.h"

struct GUI;
struct Map;
struct Entity;


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
	void UpdateView(sf::RenderWindow& window, const sf::Event& event) override;
	void UpdateEvents(sf::RenderWindow& window, Player& player, const sf::Event& event) override;

	void CloseLevel() override;


	// ______ VARIABLES ______ \\

		
	Resources r;

	sf::View mapView;

	std::unique_ptr<Map> map;

	std::unique_ptr<GUI> gui;	

	std::vector<std::unique_ptr<Entity>> NPCs;


};
