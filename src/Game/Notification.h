#pragma once

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

struct Resources;

struct Notification
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Notification();
	Notification(const sf::Font* font,const std::string& text, const Resources& r, sf::RenderWindow& window);
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

