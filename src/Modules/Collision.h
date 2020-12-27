
#pragma once

#include "..\Entities\Player.h"

// check if pixels are overlapping
static bool isOverlapping(const Entity& subject, const Entity& target)
{
	return subject.sprite.getGlobalBounds().intersects(target.sprite.getGlobalBounds());
}

// determine who wins exchange
static void ResolveConflict(Entity& subject, Entity& target)
{

	// fetch movement data
	float subjectX = std::abs(subject.movement.velocity.x);
	float subjectY = std::abs(subject.movement.velocity.y);

	float targetX = std::abs(target.movement.velocity.x);
	float targetY = std::abs(target.movement.velocity.y);

	int subjectEnergy = static_cast<int>(subjectX + subjectY);
	int targetEnergy = static_cast<int>(targetX + targetY);


	// protaganist wins
	if (subjectEnergy > targetEnergy)
	{
		target.movement.xCoord += ((subjectEnergy - targetEnergy) * subject.movement.velocity.x);
		target.movement.yCoord += ((subjectEnergy - targetEnergy) * subject.movement.velocity.y);
	}
	// antaganist wins
	else if (targetEnergy > subjectEnergy)
	{
		subject.movement.xCoord += ((targetEnergy - subjectEnergy) * target.movement.velocity.x);
		subject.movement.yCoord += ((targetEnergy - subjectEnergy) * target.movement.velocity.y);
	}
	// equal momentum
	else
	{
		subject.movement.xCoord += (target.movement.velocity.x);
		subject.movement.yCoord += (target.movement.velocity.y);

		target.movement.xCoord += (subject.movement.velocity.x);
		target.movement.yCoord += (subject.movement.velocity.y);
	}
}

static void Consolidate(std::vector<std::unique_ptr<Entity>>& npcs, Player& player)
{

	// player queries npc
	for (auto& npc : npcs)
	{
		if (isOverlapping(player, *npc))
		{
			ResolveConflict(player, *npc);
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
				if (isOverlapping(*npc, *othernpc))
				{
					ResolveConflict(*npc, *othernpc);
				}
			}
		}
	}

	// player queries world 

	// npc queries world
}


