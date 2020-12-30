#pragma once

#include "..\Modules\Animation.h"

#include "Entity.h"

struct NPC : public Entity
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	NPC(sf::RenderWindow& window, Resources& r, const std::string& name, bool enableMovement, sf::Vector2f coord, float speed, float dir);
	void Initialise(sf::RenderWindow& window, Resources& r, const std::string& name, bool enableMovement, sf::Vector2f coord, float speed, float dir);

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, Resources& r) override;

	// ______ VARIABLES ______ \\

	sf::Clock clock;

	Animation animation;

	sf::IntRect sourceSprite{0, 64, 64, 64};

};

