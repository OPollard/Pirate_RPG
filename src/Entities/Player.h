#pragma once


#include "..\Modules\Animation.h"
#include "..\Modules\Attachment.h"

#include "Entity.h"



struct Player : public Entity
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	void Initialise(sf::RenderWindow& window, const Resources& r);

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, const Resources& r) override;
	void Render(sf::RenderWindow& window) const;
	void MovementInput(sf::RenderWindow& window, const Resources& r);
	void KeyInput(sf::RenderWindow& window, const Resources& r, const sf::Event& event);
	

	void MoveUp(sf::RenderWindow& window, const Resources& r);
	void MoveDown(sf::RenderWindow& window, const Resources& r);
	void MoveRight(sf::RenderWindow& window, const Resources& r);
	void MoveLeft(sf::RenderWindow& window, const Resources& r);
	void MoveFinish();

	void RandomiseLoot(const Resources& r);

	
	// ______ VARIABLES ______ \\

	Attachment leftHand;
	Attachment rightHand;

	const float itemScale = 2.0;

	sf::Clock clock;

	Animation animation;
	sf::IntRect sourceSprite{ 0, 64, 64, 64 };

	bool pressed = false;
	bool moveIntent = false;
};

