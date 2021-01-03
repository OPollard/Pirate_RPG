#pragma once


#include "..\Modules\Animation.h"
#include "..\Modules\Attachment.h"

#include "Entity.h"



struct Player : public Entity
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	void Initialise(sf::RenderWindow& window, Resources& r);

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, Resources& r) override;
	void Render(sf::RenderWindow& window);
	void MovementInput(sf::RenderWindow& window, Resources& r);
	void KeyInput(sf::RenderWindow& window, Resources& r, sf::Event& event);
	

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

	bool pressed = false;

};

