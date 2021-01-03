
#include "Resources.h"

#include "Tile.h"

// static definitions
float Tile::animDuration = 4.0f;

Tile::Tile()
{
	walkable = false;
	animated = false;
	horizontalAnim = false;
}

// singular 
Tile::Tile(const sf::Texture& texture, const sf::IntRect& sourceRect, bool walkable, bool animated, const bool horizontalAnim )
{
	this->walkable = walkable;
	this->animated = animated;
	this->horizontalAnim = horizontalAnim;

	sprite.setTexture(texture);
	sprite.setTextureRect(sourceRect);
}

// collection
Tile::Tile(std::vector<sf::Texture>& textures)
{
	walkable = false;
	animated = false;
	horizontalAnim = false;
}

// update animated tiles
void Tile::Update(sf::Clock& clock, const Resources& r)
{
	if (animated)
	{
		animation.Update(sourceSprite, r.spriteRect, clock, animDuration, 4, horizontalAnim);
		sprite.setTextureRect(sourceSprite);
	}
}

Tile::~Tile()
{

}

