#pragma once

#include "SFML/Graphics.hpp"

struct Attachment;

struct Animation
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Animation();
	~Animation();

	// ______ FUNCTIONS ______ \\
	
	void Update(sf::IntRect& sourceSprite, const sf::IntRect& startSprite, sf::Clock& clock, float animDuration, int numFrames, bool horizontalSheet);

	// ______ SPECIFIC FUNCTIONS ______ \\

	bool WalkingItem(Attachment& attachment, sf::Clock& clock, float animDuration, bool reverse, bool vertical);

	// ______ VARIABLES ______ \\


	uint32_t frame = 0;

	std::vector<sf::Texture> frames;
	

};

