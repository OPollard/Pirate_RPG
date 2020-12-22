#pragma once

#include "..\Game\Resources.h"
#include "..\Modules\Attachment.h"


struct Animation
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Animation();
	~Animation();

	// ______ FUNCTIONS ______ \\
	
	bool Update(sf::IntRect& sourceSprite, sf::IntRect& startSprite, sf::Clock& clock, float animDuration, int numFrames);

	// ______ SPECIFIC FUNCTIONS ______ \\

	bool WalkingItem(Attachment& attachment, sf::Clock& clock, float animDuration, bool reverse, bool vertical);

	// ______ VARIABLES ______ \\


	uint32_t frame = 0;

	std::vector<sf::Texture> frames;
	

};

