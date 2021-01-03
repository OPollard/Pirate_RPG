
#include "Movement.h"


void Movement::SetXPos(int32_t x)
{
	xPos = x;
	xCoord = static_cast<float>(xPos * 32);
}

void Movement::SetYPos(int32_t y)
{
	yPos = y;
	yCoord = static_cast<float>(yPos * 32);
}

void Movement::SetPos(int32_t x, int32_t y)
{
	xPos = x;
	yPos = y;

	xCoord = static_cast<float>(xPos * 32);
	yCoord = static_cast<float>(yPos * 32);
}

void Movement::SetXCoord(float x)
{
	xCoord = x;
	xPos = static_cast<int32_t>(xCoord / 32);
}

void Movement::SetYCoord(float y)
{
	yCoord = y;
	yPos = static_cast<int32_t>(yCoord / 32);
}

void Movement::SetCoord(float x, float y)
{
	xCoord = x;
	yCoord = y;

	xPos = static_cast<int32_t>(xCoord / 32);
	yPos = static_cast<int32_t>(yCoord / 32);
}

int32_t Movement::GetXPos()
{
	return xPos;
}

int32_t Movement::GetYPos()
{
	return yPos;
}

sf::Vector2i Movement::GetPos()
{
	return sf::Vector2i(xPos, yPos);
}

float Movement::GetXCoord()
{
	return xCoord;
}

float Movement::GetYCoord()
{
	return yCoord;
}

sf::Vector2f Movement::GetCoord()
{
	return sf::Vector2f(xCoord, yCoord);
}


