
#include "World.h"

#include "State.h"



GameState::GameState()
{
	InitialiseState();
}

void GameState::InitialiseState()
{

	// init window
	window.create(sf::VideoMode(1200, 800), "Defenders");
	window.setFramerateLimit(60);

	// focus level
	levels.emplace_back(std::unique_ptr<Level>(new World(window, player)));

}

// game loop
void GameState::UpdateAndRender()
{
	
	// update current level
	if (levels.size() == 0)
	{
		CloseGame();
	}
	else
	{
		levels.back()->UpdateAndRender(window, player);

		HandleInput();
	}

}

//user input
void GameState::HandleInput()
{

	// change texture
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		CloseGame();
	}
}

// user window commands
void GameState::PollEvents()
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::EventType::Closed)
		{
			CloseGame();
		}
		if (event.type == sf::Event::EventType::Resized)
		{
			levels.back()->UpdateView(window, event);
		}
	}
}

// clean up tasks
void GameState::CloseGame()
{
	if (levels.size() != 0)
	{
		// call specific level's cleanup function
		for (auto& level : levels)
		{
			level->CloseLevel();
		}
		// void vector of pointers and data
		levels.clear();
	}

	window.close();
}

GameState::~GameState()
{

}