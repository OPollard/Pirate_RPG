
#include "Notification.h"

#include <iostream>


Notification::Notification()
{
}

Notification::Notification(sf::Font* font,
	std::string text, Resources& r, sf::RenderWindow& window)
{
	// init board
	board.setScale({ textureScalar, textureScalar });
	board.setTexture(r.notification);
	
	board.setOrigin(static_cast<float>(board.getTexture()->getSize().x/2), static_cast<float>(board.getTexture()->getSize().y/2));
	board.setPosition(window.getView().getSize().x / 2, window.getView().getSize().y - (board.getTexture()->getSize().y * textureScalar) / 2 - 50.0f);
	board.setColor({ 255,255,255, 210 });

	// init sound
	notifySound.setBuffer(r.notificationSound);
	
	// init message
	message.setFont(*font);
	message.setString(text);
	message.setFillColor(sf::Color::White);
	message.setOutlineColor(sf::Color::Black);
	message.setOutlineThickness(2.0f);
	message.setCharacterSize(32);
	message.setPosition(board.getPosition().x - message.getGlobalBounds().width / 2.0f, board.getPosition().y - message.getGlobalBounds().height / 2.0f);
	
	// text wrapping
	for (size_t index = 0; index < text.size(); ++index)
	{
		sf::Vector2f letterPosition = message.findCharacterPos(index);

		if (!board.getGlobalBounds().contains(letterPosition))
		{

			// create formatted string
			sf::String newMessage = message.getString();
			newMessage.insert(text.size() / 2, "\n");

			// init formatted message
			message.setString(newMessage);
			message.setPosition(board.getPosition().x - message.getGlobalBounds().width / 2.0f, board.getPosition().y - message.getGlobalBounds().height / 2.0f);
		}
	}

	// play noise
	notifySound.play();
}


void Notification::UpdateAndRender(sf::RenderWindow& window)
{

	// Update message position
	message.setPosition( board.getPosition().x - message.getGlobalBounds().width / 2.0f, board.getPosition().y - message.getGlobalBounds().height / 2.0f);
	board.setPosition(window.getView().getSize().x / 2, window.getView().getSize().y - (board.getTexture()->getSize().y*textureScalar) / 2 - 50.0f);
	
	// Drawing order

	window.draw(board);
	window.draw(message);
}

// called once 
bool Notification::isClicked(const sf::Vector2f& mousePos)
{
	if (!isPressed)
	{
		if (board.getGlobalBounds().contains(mousePos))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
			{
				isPressed = true;
				
			}
		}
	}
	return isPressed;
}

Notification::~Notification()
{

}