
#include "Tile.h"

// static definitions
float Tile::animDuration = 4.0f;

// singular 
Tile::Tile(sf::Texture& texture)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sourceSprite);

}

// collection
Tile::Tile(std::vector<sf::Texture>& textures)
{

}

// update animated tiles
void Tile::Update(sf::Clock& clock, Resources& r)
{
	if (animation.Update(sourceSprite, r.waves, clock, animDuration, 4))
	{
		sprite.setTextureRect(sourceSprite);
	}
}

