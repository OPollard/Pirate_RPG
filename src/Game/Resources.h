#pragma once

#include <SFML/Graphics.hpp>
#include "SFML/Audio.hpp"
#include <SFML/System.hpp>

struct Resources
{

	// ______ FUNCTIONS ______ \\

		bool LoadResources();

		bool FindFilePaths();

		bool FillPacks();

	// ______ VARIABLES ______ \\

		// PACKS
		std::vector<sf::Texture> weapons;
		std::vector<sf::Texture> shields;

		// FONTS
		sf::Font font;
		sf::Font notificationFont;

		// SOUNDS
		sf::Music music;
		sf::SoundBuffer notificationSound;

		// TEXTURES
		sf::Texture notification;	
		
		sf::Texture ocean;
		sf::IntRect waves{ 0,64,64,64 };

		// CHARACTERS
		sf::Texture player;
		sf::IntRect walkUp{ 768, 64, 64, 64 };
		sf::IntRect walkDown{ 0, 64, 64, 64 };
		sf::IntRect walkRight{ 512, 64, 64, 64 };
		sf::IntRect walkLeft{ 256, 64, 64, 64 };

		// WEAPONS
		sf::Texture battleaxe;
		sf::Texture lumberjack;
		sf::Texture one_handed;
		sf::Texture tomahawk;
		sf::Texture wedge;

		sf::Texture baton;
		sf::Texture bludgeon;
		sf::Texture club;
		sf::Texture cudgel;
		sf::Texture mace;

		sf::Texture halberd;
		sf::Texture pike;
		sf::Texture pole;
		sf::Texture sickle;
		sf::Texture spear;

		sf::Texture cleaver;
		sf::Texture cutlass;
		sf::Texture foil;
		sf::Texture rapier;
		sf::Texture sabre;
		sf::Texture scimitar;
		sf::Texture sword;
		sf::Texture sword_broad;
		sf::Texture sword_great;
		sf::Texture sword_king;

		// SHIELDS

		sf::Texture buckler_wooden;
		sf::Texture buckler_iron;
		sf::Texture buckler_steel;
		sf::Texture buckler_eternal;

		sf::Texture heater_wooden;
		sf::Texture heater_iron;

		sf::Texture kite_wooden;
		sf::Texture kite_iron;

		sf::Texture wankel_wooden;
		sf::Texture wankel_iron;

		
};
