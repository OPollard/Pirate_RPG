#pragma once

#include "Notification.h"


struct GUI
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	GUI();
	GUI(sf::RenderWindow& window, Resources& r);
	~GUI();

	// ______ FUNCTIONS ______ \\

	void Update(sf::RenderWindow& window, sf::Vector2f mousePos);
	void UpdateFPS(sf::RenderWindow& window);
	void UpdateMessages(sf::RenderWindow& window, sf::Vector2f mousePos);

	void CreateNotification(sf::RenderWindow& window, Resources& r, const std::string& text, int messageID);
	void RemoveNotification();
	

	// ______ VARIABLES ______ \\

	std::vector<Notification> messages;
	std::vector<int> messageIDs;
	Notification message;

	sf::Clock clock;
	sf::Uint64 frame;
	sf::Text fps;

};

