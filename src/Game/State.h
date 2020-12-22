#pragma once

#include "..\Entities\Player.h"
#include "Level.h"


struct GameState
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
		GameState();
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

