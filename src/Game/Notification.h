#pragma once

#include "Resources.h"


struct Notification
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Notification();
	Notification(sf::Font* font, std::string text, Resources& r, sf::RenderWindow& window);
	~Notification();

	// ______ FUNCTIONS ______ \\

	void UpdateAndRender(sf::RenderWindow& window);
	bool isClicked(const sf::Vector2f& mousePos);

	// ______ VARIABLES ______ \\ 
	
	bool isPressed = false;
	float textureScalar = 1.5f;

	sf::Text message;
	sf::Sound notifySound;
	sf::Sprite board;

};

