
#pragma once

#include "Resources.h"
#include "..\Modules\Animation.h"

struct Tile
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Tile(sf::Texture& texture);
	Tile(std::vector<sf::Texture>& textures);

	// ______ FUNCTIONS ______ \\
	
	void Update(sf::Clock& clock, Resources& r);


	// ______ VARIABLES ______ \\

	static float animDuration;

	sf::Sprite sprite;
	sf::IntRect sourceSprite{ 0,0,64,64 };

	Animation animation;

};

