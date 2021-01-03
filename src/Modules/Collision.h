
#pragma once

#include "..\Entities\Player.h"
#include "..\Entities\Prop.h"
#include "..\Modules\Math.h"


// check if pixels are overlapping with next move
static bool Overlaps(const Entity& subject, const Entity& target)
{
	// next frame bounds
	sf::FloatRect nextPosition = subject.sprite.getGlobalBounds();

	nextPosition.left += subject.movement.velocity.x;
	nextPosition.top += subject.movement.velocity.y;

	// check future collision
	return nextPosition.intersects(target.sprite.getGlobalBounds());
}

// Halt NPC movement
static void StopMovement(Entity& target)
{
	target.movement.SetXCoord(target.movement.GetXCoord() - target.movement.velocity.x);
	target.movement.SetYCoord(target.movement.GetYCoord() - target.movement.velocity.y);

}


// reverse NPC's velocities
static void ReboundNPCs(Entity& subject, Entity& target)
{
	// bool switch to force only 1 directional velocity flip
	bool isXFlipped = false;

	// next frame x position
	sf::FloatRect nextXPosition = subject.sprite.getGlobalBounds();
	nextXPosition.left += subject.movement.velocity.x;

	// check future collision
	if (nextXPosition.intersects(target.sprite.getGlobalBounds()))
	{
		// reverse horizontal vector
		Inverse(subject.movement.velocity.x);
		Inverse(target.movement.velocity.x);

		// prevents y flipping
		isXFlipped = true;
	}

	// same but vertical vector
	if (!isXFlipped)
	{
		sf::FloatRect nextYPosition = subject.sprite.getGlobalBounds();
		nextYPosition.top += subject.movement.velocity.y;

		if (nextYPosition.intersects(target.sprite.getGlobalBounds()))
		{
			Inverse(subject.movement.velocity.y);
			Inverse(target.movement.velocity.y);
		}
	}
}

// complete collision script
static void Consolidate(std::vector<std::unique_ptr<Entity>>& npcs, Player& player, std::vector<Prop>& props)
{

	// player queries npc
	for (auto& npc : npcs)
	{
		if (Overlaps(player, *npc))
		{
			StopMovement(*npc);
		}
	}

	// npc queries npc
	for (auto& npc : npcs)
	{
		for (auto& othernpc : npcs)
		{
			// prevent querying self
			if (npc != othernpc)
			{
				if (Overlaps(*npc, *othernpc))
				{
					ReboundNPCs(*npc, *othernpc);
				}
			}
		}
	}

	// player queries world 
	for (auto& p : props)
	{
		if (Overlaps(player, p))
		{
			StopMovement(player);
		}
	}

	// npc queries world
}


