#pragma once

#include "..\Game\Resources.h"
#include "Entity.h"
#include "..\Modules\Animation.h"
#include "..\Modules\Attachment.h"

struct Player : public Entity
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	void Initialise(sf::RenderWindow& window, Resources& r);

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, Resources& r) override;
	void Render(sf::RenderWindow& window);
	void HandleInput(sf::RenderWindow& window, Resources& r);

	void MoveUp(sf::RenderWindow& window, Resources& r);
	void MoveDown(sf::RenderWindow& window, Resources& r);
	void MoveRight(sf::RenderWindow& window, Resources& r);
	void MoveLeft(sf::RenderWindow& window, Resources& r);

	void RandomiseLoot(Resources& r);

	
	// ______ VARIABLES ______ \\

	Attachment leftHand;
	Attachment rightHand;

	float itemScale = 2.0;

	sf::Clock clock;

	Animation animation;
	sf::IntRect sourceSprite{ 0, 64, 64, 64 };

	bool clicked = false;
};

