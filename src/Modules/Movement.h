#pragma once

#include "..\Game\Resources.h"

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


	// ______ VARIABLES ______ \\


	bool enableMovement = false;
	
	float speed = 0.0f;

	sf::Vector2f direction = { 0.0f, 0.0f };
	sf::Vector2f velocity = { 0.0f, 0.0f };

	float xCoord = 0.0f;
	float yCoord = 0.0f;


	eDirection facing = eDirection::SOUTH;
};
