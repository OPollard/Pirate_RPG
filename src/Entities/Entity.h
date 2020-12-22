#pragma once

#include "..\Game\Resources.h"
#include "..\Modules\Movement.h"

struct Entity
{

	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\
	
	// ______ FUNCTIONS ______ \\

	virtual void Update(sf::RenderWindow& window, Resources& r);


	// ______ VARIABLES ______ \\

	sf::Sprite sprite;

	std::string name = "None";

	Movement movement;


};