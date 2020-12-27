
#pragma once

#include "..\Modules\Animation.h"

struct Resources;

struct Tile
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	Tile();
	Tile(sf::Texture& texture);
	Tile(std::vector<sf::Texture>& textures);
	~Tile();

	// ______ FUNCTIONS ______ \\
	
	void Update(sf::Clock& clock, Resources& r);


	// ______ VARIABLES ______ \\

	static float animDuration;

	sf::Sprite sprite;
	sf::IntRect sourceSprite{ 0,0,64,64 };

	Animation animation;

};

