

#include "..\Game\State.h"
#include "..\Modules\Math.h"
#include "..\Game\Resources.h"

#include "NPC.h"


NPC::NPC(sf::RenderWindow& window, Resources& r, const std::string& name, bool enableMovement, sf::Vector2f coord, float speed, float dir)
{
	Initialise(window, r, name, enableMovement, coord, speed, dir);
}


void NPC::Initialise(sf::RenderWindow& window, Resources& r, const std::string& name, bool enableMovement, sf::Vector2f coord, float speed, float dir)
{
	// init attributes
	this->name = name;

	// init movement component
	movement.enableMovement = enableMovement;
	movement.speed = speed;
	movement.direction = { AngleToX(dir), AngleToY(dir)};
	movement.velocity = { movement.direction.x * speed, movement.direction.y * speed };

	movement.xCoord = coord.x;
	movement.yCoord = coord.y;

	// init sprite 
	sprite.setTexture(r.player);
	sprite.setTextureRect(sourceSprite);
	sprite.setOrigin(static_cast<float>(sprite.getTextureRect().width / 2), static_cast<float>(sprite.getTextureRect().height / 2));
	sprite.setPosition(movement.xCoord, movement.yCoord);

	// init clock
	clock.restart();
}

void NPC::Update(sf::RenderWindow& window, Resources& r)
{
	

	if (movement.yCoord > 400.0f && std::abs(movement.velocity.y) > 0.1f)
	{
		movement.velocity.y = -(movement.direction.y * movement.speed) ;
	}
	if (movement.yCoord < 50.0f && std::abs(movement.velocity.y) > 0.1f)
	{
		movement.velocity.y = (movement.direction.y * movement.speed);
	}
	if (movement.xCoord > 400.0f && std::abs(movement.velocity.x) > 0.1f)
	{
		movement.velocity.x = (movement.direction.x * movement.speed);
	}
	if (movement.xCoord < 50.0f && std::abs(movement.velocity.x) > 0.1f)
	{
		movement.velocity.x = -(movement.direction.x * movement.speed);
	}

	// movement
	movement.xCoord += movement.velocity.x;
	movement.yCoord += movement.velocity.y;

	// moving up
	if (movement.velocity.x < -0.1f)
	{
		animation.Update(sourceSprite, r.walkLeft, clock, 1 / (movement.speed / 2), 4);
	}
	else if (movement.velocity.x > 0.1f)
	{
		animation.Update(sourceSprite, r.walkRight, clock, 1 / (movement.speed / 2), 4);
	}
	else if (movement.velocity.y > 0.1f)
	{
		animation.Update(sourceSprite, r.walkDown, clock, 1 / (movement.speed / 2), 4);
	}
	else if (movement.velocity.y < -0.1f)
	{
		animation.Update(sourceSprite, r.walkUp, clock, 1 / (movement.speed / 2), 4);
	}
	else
	{
		sourceSprite = { 0,0,64,64 };
	}
	
	// apply new sprite
	sprite.setTextureRect(sourceSprite);

	// sprite
	sprite.setPosition(movement.xCoord, movement.yCoord);

	// render
	window.draw(sprite);

}

