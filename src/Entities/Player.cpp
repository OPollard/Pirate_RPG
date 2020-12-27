
#include "..\Game\State.h"
#include "..\Game\Resources.h"

#include "Player.h"

void Player::Initialise(sf::RenderWindow& window, Resources& r)
{

	// init attributes
	name = "Player";

	// init movement componenet
	movement.enableMovement = true;
	movement.speed = 3.0f;
	movement.direction = { 0.0f, 0.0f };
	movement.velocity = { 0.0f, 0.0f };
	
	movement.xCoord = 100;
	movement.yCoord = 100;
	
	// init sprite 
	sprite.setTexture(r.player);
	sprite.setTextureRect(sourceSprite);
	sprite.setOrigin(static_cast<float>(sprite.getTextureRect().width/2),static_cast<float>(sprite.getTextureRect().height/2));
	sprite.setPosition((float)movement.xCoord, (float)movement.yCoord);

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

void Player::Update(sf::RenderWindow& window, Resources& r)
{
	// position
	sprite.setPosition((float)movement.xCoord, (float)movement.yCoord);
	leftHand.sprite.setPosition(sprite.getPosition() + leftHand.offset);
	rightHand.sprite.setPosition(sprite.getPosition() + rightHand.offset);

	// user input
	HandleInput(window, r);

	// draw character
	Render(window);

}

// draw all player components
void Player::Render(sf::RenderWindow& window)
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
void Player::HandleInput(sf::RenderWindow& window, Resources& r)
{
	
	typedef sf::Keyboard k;

	// reset for new input
	movement.direction = { 0.0f, 0.0f };


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

		if (k::isKeyPressed(k::F) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
		{
			if (!clicked)
			{
				RandomiseLoot(r);
				clicked = true;
			}
		}
		else
		{
			clicked = false;
		}

}

void Player::RandomiseLoot(Resources& r)
{

	// random
	int index = std::rand() % 25;

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
	int sIndex = std::rand() % 10;
	
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
void Player::MoveUp(sf::RenderWindow& window, Resources& r)
{
	// set movement
	movement.direction += { 0.0f, -1.0f };
	movement.facing = eDirection::NORTH;
	movement.velocity = { movement.direction.x * movement.speed, movement.direction.y * movement.speed };
	movement.xCoord += movement.velocity.x;
	movement.yCoord += movement.velocity.y;

	// set attachment
	leftHand.offset = { -22.5f, 0.0f };
	rightHand.offset = { 15.0f, 10.0f };
	leftHand.sprite.setScale(-itemScale, itemScale);
	leftHand.sprite.setRotation(-35.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkUp, clock, 1 / (movement.speed / 2), 4);

	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), false, true);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), true, true);

	// apply new sprite
	sprite.setTextureRect(sourceSprite);

	
}

void Player::MoveDown(sf::RenderWindow& window, Resources& r)
{
	// set movement
	movement.direction += { 0.0f, 1.0f };
	movement.facing = eDirection::SOUTH;
	movement.velocity = { movement.direction.x * movement.speed, movement.direction.y * movement.speed };
	movement.xCoord += movement.velocity.x;
	movement.yCoord += movement.velocity.y;

	// set attachment
	leftHand.offset = { 22.5f, 0.0f };
	rightHand.offset = { -15.0f, 10.0f };
	leftHand.sprite.setScale(itemScale, itemScale);
	leftHand.sprite.setRotation(35.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkDown, clock, 1 / (movement.speed / 2), 4);

	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), true, true);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), false, true);

	// apply new sprite
	sprite.setTextureRect(sourceSprite);

}

void Player::MoveRight(sf::RenderWindow& window, Resources& r)
{

	// set movement
	movement.direction += { 1.0f, 0.0f };
	movement.facing = eDirection::EAST;
	movement.velocity = { movement.direction.x * movement.speed, movement.direction.y * movement.speed };
	movement.xCoord += movement.velocity.x;
	movement.yCoord += movement.velocity.y;

	// set attachment
	leftHand.offset = { 12.5f, 5.0f };
	rightHand.offset = { 0.0f, 10.0f };
	leftHand.sprite.setScale(itemScale, itemScale);
	leftHand.sprite.setRotation(60.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkRight, clock, 1 / (movement.speed / 2), 4);
	
	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), false, false);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), true, false);

	// apply new sprite
	sprite.setTextureRect(sourceSprite);

}

void Player::MoveLeft(sf::RenderWindow& window, Resources& r)
{

	// set movement
	movement.direction += { -1.0f, 0.0f };
	movement.facing = eDirection::WEST;
	movement.velocity = { movement.direction.x * movement.speed, movement.direction.y * movement.speed };
	movement.xCoord += movement.velocity.x;
	movement.yCoord += movement.velocity.y;

	// set attachment
	leftHand.offset = { -12.5f, 5.0f };
	rightHand.offset = { 0.0f, 10.0f };
	leftHand.sprite.setScale(-itemScale, itemScale);
	leftHand.sprite.setRotation(-60.0f); 

	// update character animation
	animation.Update(sourceSprite, r.walkLeft, clock, 1 / (movement.speed / 2), 4);

	// update attachment animation
	animation.WalkingItem(leftHand, clock, 1 / (movement.speed / 2), true, false);
	animation.WalkingItem(rightHand, clock, 1 / (movement.speed / 2), false, false);

	// apply new sprite
	sprite.setTextureRect(sourceSprite);


}
