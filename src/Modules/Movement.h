#pragma once

#include "SFML/Graphics.hpp"

enum class eDirection
{
		NORTH,
		SOUTH,
		EAST,
		WEST
};

struct Movement
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	// ______ FUNCTIONS ______ \\

	void SetXPos(int32_t x);
	void SetYPos(int32_t y);
	void SetPos(int32_t x, int32_t y);

	void SetXCoord(float x);
	void SetYCoord(float y);
	void SetCoord(float x, float y);

	int32_t GetXPos();
	int32_t GetYPos();
	sf::Vector2i GetPos();

	float GetXCoord();
	float GetYCoord();
	sf::Vector2f GetCoord();


	// ______ VARIABLES ______ \\


	bool enableMovement = false;
	
	float speed = 0.0f;

	sf::Vector2f direction = { 0.0f, 0.0f };
	sf::Vector2f velocity = { 0.0f, 0.0f };

	eDirection facing = eDirection::SOUTH;

private:

	float xCoord = 0.0f;
	float yCoord = 0.0f;

	int32_t xPos = 0;
	int32_t yPos = 0;


	
};
