
#pragma once

#include "..\Modules\Animation.h"

struct Resources;

struct Tile
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	Tile();
	Tile(const sf::Texture& texture, const sf::IntRect& sourceRect, bool walkable, bool animated = false, const bool horizontalAnim = false);
	Tile(std::vector<sf::Texture>& textures);
	~Tile();

	// ______ FUNCTIONS ______ \\
	
	void Update(sf::Clock& clock, const Resources& r);


	// ______ VARIABLES ______ \\

	bool walkable = false;
	bool animated = false;
	bool horizontalAnim = false;

	static float animDuration;

	sf::Sprite sprite;
	sf::IntRect sourceSprite{ 0,0,32,32 };

	Animation animation;

};

