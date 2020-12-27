

#include <sstream>

#include "Resources.h"

#include "GUI.h"


GUI::GUI()
{
}

GUI::GUI(sf::RenderWindow& window, Resources& r)
{
	// init fps
	frame = 0;
	fps.setPosition(25, 25);
	fps.setCharacterSize(30);
	fps.setFillColor(sf::Color::White);
	fps.setFont(r.font);
}


void GUI::Update(sf::RenderWindow& window, sf::Vector2f mousePos)
{
	UpdateFPS(window);
	UpdateMessages(window, mousePos);
}

// fps counter
void GUI::UpdateFPS(sf::RenderWindow & window)
{
	frame++;

	float t1 = clock.getElapsedTime().asSeconds();
	
	if (t1 >= 1.0f)
	{
		std::stringstream ss;
		ss << "FPS: " << frame;
		fps.setString(ss.str());
		frame = 0;
		clock.restart();
	}

	window.draw(fps);
}

// message stack
void GUI::UpdateMessages(sf::RenderWindow& window, sf::Vector2f mousePos)
{
	if (messages.size() != 0)
	{
		// top notification
		message = messages.back();
		
		if (!message.isClicked(mousePos))
		{
			message.UpdateAndRender(window);
		}
		else
		{
			RemoveNotification();
		}
	}
}

// create new notification
void GUI::CreateNotification(sf::RenderWindow& window, Resources& r, const std::string& text, int messageID)
{

	bool alreadyRequested = false;
	
	// check if already logged
	for (auto id : messageIDs)
	{
		if (id == messageID)
		{
			alreadyRequested = true;
		}
	}

	// log new message
	if (!alreadyRequested)
	{
		messageIDs.push_back(messageID);
		messages.push_back(Notification(&r.notificationFont, text, r, window));
	}
	
	
}

// remove last message
void GUI::RemoveNotification()
{
	if (messages.size() != 0)
	{
		messages.pop_back();
	}

	if (messageIDs.size() != 0)
	{
		messageIDs.pop_back();
	}
}

GUI::~GUI()
{

}