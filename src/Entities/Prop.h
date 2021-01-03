#pragma once

#include "Entity.h"

struct Prop : public Entity
{
	// ______ CONSTRUCTORS, DESTRUCTORS & INITIALISERS ______ \\

	Prop() = delete;
	Prop(const std::string& name, const sf::Texture& sourceTexure, const sf::IntRect sourceSprite, int32_t xPos = 0, int32_t yPos = 0, bool canMove = false, bool interactable = false, bool destructable = false);
	~Prop();
	
	// ______ FUNCTIONS ______ \\

	virtual void Update(sf::RenderWindow& window, const Resources& r) override;

	// ______ VARIABLES ______ \\

	bool interactable = false;
	bool destructable = false;
};

