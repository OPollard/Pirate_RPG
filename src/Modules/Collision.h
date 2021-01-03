
#pragma once

#include "..\Entities\Player.h"
#include "..\Entities\Prop.h"
#include "..\Game\Map.h"
#include "..\Game\Tile.h"
#include "..\Modules\Math.h"


// check if next tile is walkable
static bool WalkableFloor(Entity& subject, const Map& map)
{
	// predicted player grid poisiton
	const int32_t nextGridX = static_cast<int32_t>((subject.movement.GetXCoord() + subject.movement.velocity.x) / map.gridUnit);
	const int32_t nextGridY = static_cast<int32_t>((subject.movement.GetYCoord() + subject.movement.velocity.y) / map.gridUnit) + 1;

	return (map.map[nextGridX][nextGridY]) ? map.map[nextGridX][nextGridY]->walkable : false;
}

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

// Halt  movement
static void StopMovement(Entity& target)
{
	target.movement.SetXCoord(target.movement.GetXCoord() - target.movement.velocity.x);
	target.movement.SetYCoord(target.movement.GetYCoord() - target.movement.velocity.y);
}


// reverse NPC's velocities
static void ReboundEntities(Entity& subject, Entity& target, const bool reboundTarget)
{
	// ensures only direction will change
	bool isXFlipped = false;

	// predict future x placement
	sf::FloatRect nextXPosition = subject.sprite.getGlobalBounds();
	nextXPosition.left += subject.movement.velocity.x;

	if (nextXPosition.intersects(target.sprite.getGlobalBounds()))
	{
		// reverse horizontal vector
		Inverse(subject.movement.velocity.x);

		if(reboundTarget) Inverse(target.movement.velocity.x);

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
			if(reboundTarget) Inverse(target.movement.velocity.y);
		}
	}
}

// reverse NPC's velocity
static void ReboundEntity(Entity& subject)
{
	Inverse(subject.movement.velocity.y);
	Inverse(subject.movement.velocity.x);
}

// complete collision script
static void Consolidate(std::vector<std::unique_ptr<Entity>>& npcs, Player& player, Map& map)
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
					ReboundEntities(*npc, *othernpc, true);
				}
			}
		}
	}

	// player queries prop 
	for (auto& p : map.props)
	{
		if (Overlaps(player, p))
		{
			StopMovement(player);
		}
	}

	// player queries tiles
	if (!WalkableFloor(player, map))
	{
		StopMovement(player);
	}


	// npc queries world
	for (auto& n : npcs)
	{
		// prop query
		for (auto& p : map.props)
		{
			if (Overlaps(*n, p))
			{
				ReboundEntities(*n, p, false);
			}
		}

		// tile query
		if (!WalkableFloor(*n, map))
		{
			ReboundEntity(*n);
		}
	}

}


