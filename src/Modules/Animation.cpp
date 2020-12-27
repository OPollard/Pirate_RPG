

#include "..\Modules\Attachment.h"

#include "Animation.h"

Animation::Animation()
{
}


bool Animation::Update(sf::IntRect& sourceSprite, sf::IntRect& startSprite, sf::Clock& clock, float animDuration, int numFrames)
{
	if (clock.getElapsedTime().asSeconds() < animDuration)
	{
		sourceSprite.left = startSprite.left + (int)((clock.getElapsedTime().asSeconds() / (animDuration / numFrames))) * sourceSprite.width;
	}
	else
	{
		clock.restart();
	}
	return true;
}


bool Animation::WalkingItem(Attachment& attachment, sf::Clock& clock, float animDuration, bool reverse, bool vertical)
{

	if (clock.getElapsedTime().asSeconds() < (animDuration / 4))
	{
		if(vertical) (!reverse) ? attachment.offset.y -= 5.0f : attachment.offset.y += 5.0f;
		else (!reverse) ? attachment.offset.x -= 5.0f : attachment.offset.x += 5.0f;
	}
	else if (clock.getElapsedTime().asSeconds() < (animDuration / 4) * 2)
	{
		attachment.offset.y += 0.0f;
		attachment.offset.x += 0.0f;
	}
	else if (clock.getElapsedTime().asSeconds() < (animDuration / 4) * 3)
	{
		if (vertical) (!reverse) ? attachment.offset.y += 5.0f : attachment.offset.y -= 5.0f;
		else (!reverse) ? attachment.offset.x += 5.0f : attachment.offset.x -= 5.0f;
	}
	else if (clock.getElapsedTime().asSeconds() < animDuration)
	{
		attachment.offset.y -= 0.0f;
		attachment.offset.x -= 0.0f;
	}
	else
	{
		clock.restart();
	}

	return true;
}

Animation::~Animation()
{
}
