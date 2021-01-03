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

		// DATA
		std::string mapDataFilePath;
		std::string propLocationsFilePath;

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
		sf::Texture objSheet;
		sf::Texture ocean;

		sf::IntRect sandRect{ 192, 0, 32, 32 };
		sf::IntRect grassRect{ 0, 128, 32,32 };
		sf::IntRect spriteRect{ 0,0,32,32 };

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

		// PLANTS
		sf::IntRect tree_lightgreen_tl = { 0,32,32,32 };
		sf::IntRect tree_lightgreen_tr = { 32,32,32,32 };
		sf::IntRect tree_lightgreen_bl = { 0, 64,32,32 };
		sf::IntRect tree_lightgreen_br = { 32,64,32,32 };

		// CONTAINERS
		sf::IntRect pot_closed_beige = { 0,0,32,32 };
		sf::IntRect pot_open_beige = { 32,0,32,32 };
		sf::IntRect chest_closed_red = { 192,160,32,32 };

};

