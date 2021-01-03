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

	void SetXPos(const int32_t x);
	void SetYPos(const int32_t y);
	void SetPos(const int32_t x, const int32_t y);

	void SetXCoord(const float x);
	void SetYCoord(const float y);
	void SetCoord(const float x, const float y);

	int32_t GetXPos() const;
	int32_t GetYPos() const;
	sf::Vector2i GetPos() const;

	float GetXCoord() const;
	float GetYCoord() const;
	sf::Vector2f GetCoord() const;


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
