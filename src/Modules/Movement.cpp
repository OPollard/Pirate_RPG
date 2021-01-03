
#include "Movement.h"


void Movement::SetXPos(const int32_t x)
{
	xPos = x;
	xCoord = static_cast<float>(xPos * 32);
}

void Movement::SetYPos(const int32_t y)
{
	yPos = y;
	yCoord = static_cast<float>(yPos * 32);
}

void Movement::SetPos(const int32_t x, const int32_t y)
{
	xPos = x;
	yPos = y;

	xCoord = static_cast<float>(xPos * 32);
	yCoord = static_cast<float>(yPos * 32);
}

void Movement::SetXCoord(const float x)
{
	xCoord = x;
	xPos = static_cast<int32_t>(xCoord / 32);
}

void Movement::SetYCoord(const float y)
{
	yCoord = y;
	yPos = static_cast<int32_t>(yCoord / 32);
}

void Movement::SetCoord(const float x, const float y)
{
	xCoord = x;
	yCoord = y;

	xPos = static_cast<int32_t>(xCoord / 32);
	yPos = static_cast<int32_t>(yCoord / 32);
}

int32_t Movement::GetXPos() const
{
	return xPos;
}

int32_t Movement::GetYPos() const
{
	return yPos;
}

sf::Vector2i Movement::GetPos() const
{
	return sf::Vector2i(xPos, yPos);
}

float Movement::GetXCoord() const
{
	return xCoord;
}

float Movement::GetYCoord() const
{
	return yCoord;
}

sf::Vector2f Movement::GetCoord() const
{
	return sf::Vector2f(xCoord, yCoord);
}


