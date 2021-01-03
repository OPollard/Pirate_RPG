#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <memory>

#include "..\Game\Tile.h"
#include "..\Entities\Prop.h"
#include "..\Game\Map.h"




namespace Generator
{
	// fetch and apply map data
	static void ExtractMapData(const std::string& filename, std::vector<std::vector<std::unique_ptr<Tile>>>& map, const uint32_t gridUnit, const Resources& r)
	{
		// open file
		std::ifstream inFile(filename, std::ios::in);
		 
		// set y default
		int32_t yIndex = 0;

		if (inFile.is_open())
		{
			// get every line
			std::string line;
			while (std::getline(inFile, line))
			{
				// convert string to stream for manipulation
				std::istringstream lineStream(line);

				int32_t tileType = 0;
				int32_t xIndex = 0;

				// while not at the end of the line
				while (lineStream >> tileType)
				{
					switch (tileType)
					{
						// sand
						case 1:
							map[xIndex][yIndex] = std::unique_ptr<Tile>(new Tile(r.objSheet, r.sandRect, true));
							break;
						// ocean
						default:
							map[xIndex][yIndex] = std::unique_ptr<Tile>(new Tile(r.ocean, r.spriteRect, false, true, true));
					}
					
					// align sprite to coordinates
					map[xIndex][yIndex]->sprite.setPosition(sf::Vector2f(static_cast<float>(gridUnit * xIndex), static_cast<float>(gridUnit * yIndex)));
					
					// go right through file
					xIndex++;
				}
				// go down through file
				yIndex++;
			}
		}
		inFile.close();
	}

	static bool ExtractPropMapData(const std::string& filename, std::vector<Prop>& props)
	{

	}
}