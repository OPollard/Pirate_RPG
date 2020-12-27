#pragma once

#include "SFML/Graphics.hpp"

#include "..\Entities\Player.h"

struct Level;

struct GameState
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
		GameState();
		~GameState();
		void InitialiseState();


	// ______ FUNCTIONS ______ \\
		
		void UpdateAndRender();
		void HandleInput();
		void PollEvents();
		void CloseGame();

		
	// ______ VARIABLES ______ \\
		
		Player player;

		sf::RenderWindow window;

		std::vector<std::unique_ptr<Level>> levels;

};

