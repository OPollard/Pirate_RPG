

#include "Prop.h"

Prop::Prop(std::string name, sf::Texture& sourceTexture, sf::IntRect sourceSprite, int32_t xPos, int32_t yPos, bool canMove, bool interactable, bool destructable)
{
	// init movement
	movement.SetPos(xPos, yPos);
	movement.enableMovement = canMove;

	// init entity
	this->name = name;
	sprite.setTexture(sourceTexture);
	sprite.setTextureRect(sourceSprite);
	sprite.setPosition(movement.GetCoord());

	
	// init prop
	this->interactable = interactable;
	this->destructable = destructable;

}

void Prop::Update(sf::RenderWindow& window, Resources& r)
{

}

Prop::~Prop()
{

}
