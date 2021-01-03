
#include "..\Game\State.h"
#include "..\Game\Resources.h"

#include "..\Modules\Performance.h"

#include "Player.h"

//temp
#include <iostream>


void Player::Initialise(sf::RenderWindow& window, const Resources& r)
{

	// init attributes
	name = "Player";

	// init movement componenet
	movement.enableMovement = true;
	movement.speed = 3.0f;
	movement.direction = { 0.0f, 0.0f };
	movement.velocity = { 0.0f, 0.0f };
	
	movement.SetPos(12,12); // 32 grid unit
	
	// init sprite 
	sprite.setTexture(r.player);
	sprite.setTextureRect(sourceSprite); 
	sprite.setOrigin(static_cast<float>(sprite.getTextureRect().width/2),static_cast<float>(sprite.getTextureRect().height/2));
	sprite.setPosition(movement.GetCoord());

	// init animation timer
	clock.restart();

	// init left attachment
	leftHand.sprite.setTexture(r.sword_king);
	leftHand.sprite.setRotation(35.0f);
	leftHand.sprite.setOrigin(static_cast<float>(leftHand.sprite.getTexture()->getSize().x / 2), static_cast<float>(leftHand.sprite.getTexture()->getSize().y / 2));
	leftHand.offset = { 25.0f, 0.0f };
	leftHand.sprite.setPosition(sprite.getPosition() + leftHand.offset);
	leftHand.sprite.setScale(itemScale, itemScale);

	// init right attachment
	rightHand.sprite.setTexture(r.buckler_eternal);
	rightHand.sprite.setRotation(0.0f);
	rightHand.sprite.setOrigin(static_cast<float>(rightHand.sprite.getTexture()->getSize().x / 2), static_cast<float>(rightHand.sprite.getTexture()->getSize().y / 2));
	rightHand.offset = { -15.0f, 10.0f };
	rightHand.sprite.setPosition(sprite.getPosition() + rightHand.offset);
	rightHand.sprite.setScale(itemScale, itemScale);
}

void Player::Update(sf::RenderWindow& window, const Resources& r)
{
		
	// position
	sprite.setPosition(movement.GetCoord());
	leftHand.sprite.setPosition(sprite.getPosition() + leftHand.offset);
	rightHand.sprite.setPosition(sprite.getPosition() + rightHand.offset);
	
	// user input
	MovementInput(window, r);

	// draw character
	Render(window);

}

// draw all player components
void Player::Render(sf::RenderWindow& window) const
{

	// change drawing order based on direction
	switch (movement.facing)
	{
	case eDirection::SOUTH:
		window.draw(sprite);
		window.draw(leftHand.sprite);
		window.draw(rightHand.sprite);
		break;
	case eDirection::NORTH:
		window.draw(leftHand.sprite);
		window.draw(rightHand.sprite);
		window.draw(sprite);
		break;
	case eDirection::EAST:
		window.draw(leftHand.sprite);
		window.draw(sprite);
		window.draw(rightHand.sprite);
		break;
	case eDirection::WEST:
		window.draw(rightHand.sprite);
		window.draw(sprite);
		window.draw(leftHand.sprite);
		break;
	}

}

// user input
void Player::MovementInput(sf::RenderWindow& window, const Resources& r)
{
	
	typedef sf::Keyboard k;

	// reset for new input
	movement.direction = { 0.0f, 0.0f };
	moveIntent = false;

	if (k::isKeyPressed(k::W) || k::isKeyPressed(k::Up))
	{
		MoveUp(window, r);
	}

	if (k::isKeyPressed(k::S) || k::isKeyPressed(k::Down))
	{
		MoveDown(window, r);
	}

	if (k::isKeyPressed(k::D) || k::isKeyPressed(k::Right))
	{
		MoveRight(window, r);
	}

	if (k::isKeyPressed(k::A) || k::isKeyPressed(k::Left))
	{
		MoveLeft(window, r);
	}

	if (moveIntent)
	{
		MoveFinish();
	}

}

// player keyboard / mouse commands
void Player::KeyInput(sf::RenderWindow& window, const Resources& r, const sf::Event& event)
{

	// actions on press
	if (event.type == sf::Event::KeyPressed || event.type == sf::Event::MouseButtonPressed)
	{
		typedef sf::Keyboard K;
		
		// selection
		if (event.key.code == K::E)
		{
			RandomiseLoot(r);
			std::cout << "Equipment Changed" << std::endl;
		}
		if (event.key.code == K::F || event.mouseButton.button == sf::Mouse::Right)
		{
			std::cout << "Interact" << std::endl;
		}
		if (event.key.code == K::P)
		{
			Performance::debugMode = !Performance::debugMode;

			if (Performance::debugMode) std::cout << "Debug Mode: ON" << std::endl;
			else std::cout << "Debug Mode: OFF" << std::endl;	RandomiseLoot(r);
		}
	}

}

void Player::RandomiseLoot( const Resources& r)
{

	// random
	const int index = std::rand() % 25;

	// copy new sprite locally
	sf::Sprite newWep;
	newWep.setTexture(r.weapons[index]);
	
	// set attachment
	leftHand.sprite = newWep;
	leftHand.sprite.setRotation(35.0f);
	leftHand.sprite.setOrigin(static_cast<float>(leftHand.sprite.getTexture()->getSize().x / 2), static_cast<float>(leftHand.sprite.getTexture()->getSize().y / 2));
	leftHand.offset = { 25.0f, 0.0f };
	leftHand.sprite.setPosition(sprite.getPosition() + leftHand.offset);
	leftHand.sprite.setScale(itemScale, itemScale);

	// random
	const int sIndex = std::rand() % 10;
	
	// copy new sprite locally
	sf::Sprite newShield;
	newShield.setTexture(r.shields[sIndex]);

	// set attachment
	rightHand.sprite = newShield;
	rightHand.sprite.setRotation(0.0f);
	rightHand.sprite.setOrigin(static_cast<float>(rightHand.sprite.getTexture()->getSize().x / 2), static_cast<float>(rightHand.sprite.getTexture()->getSize().y / 2));
	rightHand.offset = { -15.0f, 10.0f };
	rightHand.sprite.setPosition(sprite.getPosition() + rightHand.offset);
	rightHand.sprite.setScale(itemScale, itemScale);


}

// movement changes
void Player::MoveUp(sf::RenderWindow& window, const Resources& r)
{
	// set movement
	movement.direction += { 0.0f, -1.0f };
	movement.facing = eDirection::NORTH;

	// set attachment
	leftHand.offset = { -22.5f, 0.0f };
	rightHand.offset = { 15.0f, 10.0f };
	leftHand.sprite.setScale(-itemScale, itemScale);
	leftHand.sprite.setRotation(-35.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkUp, clock, 1 / (movement.speed / 2), 4, true);

	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), false, true);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), true, true);

	// declare intent
	moveIntent = true;

}

void Player::MoveDown(sf::RenderWindow& window, const Resources& r)
{
	// set movement
	movement.direction += { 0.0f, 1.0f };
	movement.facing = eDirection::SOUTH;

	// set attachment
	leftHand.offset = { 22.5f, 0.0f };
	rightHand.offset = { -15.0f, 10.0f };
	leftHand.sprite.setScale(itemScale, itemScale);
	leftHand.sprite.setRotation(35.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkDown, clock, 1 / (movement.speed / 2), 4, true);

	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), true, true);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), false, true);

	// declare intent
	moveIntent = true;
}

void Player::MoveRight(sf::RenderWindow& window, const Resources& r)
{
	// set movement
	movement.direction += { 1.0f, 0.0f };
	movement.facing = eDirection::EAST;

	// set attachment
	leftHand.offset = { 12.5f, 5.0f };
	rightHand.offset = { 0.0f, 10.0f };
	leftHand.sprite.setScale(itemScale, itemScale);
	leftHand.sprite.setRotation(60.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkRight, clock, 1 / (movement.speed / 2), 4, true);
	
	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), false, false);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), true, false);

	// declare intent
	moveIntent = true;
}

void Player::MoveLeft(sf::RenderWindow& window, const Resources& r)
{
	// set movement
	movement.direction += { -1.0f, 0.0f };
	movement.facing = eDirection::WEST;

	// set attachment
	leftHand.offset = { -12.5f, 5.0f };
	rightHand.offset = { 0.0f, 10.0f };
	leftHand.sprite.setScale(-itemScale, itemScale);
	leftHand.sprite.setRotation(-60.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkLeft, clock, 1 / (movement.speed / 2), 4, true);

	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), true, false);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), false, false);

	// declare intent
	moveIntent = true;
}

// unified move actions
void Player::MoveFinish()
{
	// apply movement
	movement.velocity = { movement.direction.x * movement.speed, movement.direction.y * movement.speed };
	movement.SetCoord(movement.GetXCoord() + movement.velocity.x, movement.GetYCoord() + movement.velocity.y);

	// apply new sprite
	sprite.setTextureRect(sourceSprite);
}
