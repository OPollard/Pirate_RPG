
#include "Resources.h"

// loading sequence
bool Resources::LoadResources()
{
	if (!FindFilePaths()) return false;
	if (!FillPacks()) return false;

	return true;
}

bool Resources::FindFilePaths()
{
	// debug resource file paths
#if _DEBUG

	// data
	mapDataFilePath = "../assets/world/mapdata.txt";

	// fonts
	if (!font.loadFromFile("../assets/fonts/arial.ttf"))								return false;
	if (!notificationFont.loadFromFile("../assets/fonts/notificationfont.ttf"))			return false;

	// sounds
	if (!music.openFromFile("../assets/sounds/stardew.wav"))							return false;
	if (!notificationSound.loadFromFile("../assets/sounds/notificationsound.wav"))		return false;

	// textures
	if (!notification.loadFromFile("../assets/textures/notificationboard.png"))			return false;
	if (!objSheet.loadFromFile("../assets/textures/chip.png"))							return false;
	if (!ocean.loadFromFile("../assets/textures/ocean.png"))							return false;

	// characters
	if (!player.loadFromFile("../assets/characters/player.png"))						return false;

	// weapons
	if (!battleaxe.loadFromFile("../assets/weapons/axes/battleaxe.png"))				return false;
	if (!lumberjack.loadFromFile("../assets/weapons/axes/lumberjack.png"))				return false;
	if (!one_handed.loadFromFile("../assets/weapons/axes/one_handed.png"))				return false;
	if (!tomahawk.loadFromFile("../assets/weapons/axes/tomahawk.png"))					return false;
	if (!wedge.loadFromFile("../assets/weapons/axes/wedge.png"))						return false;
		
	if (!baton.loadFromFile("../assets/weapons/clubs/baton.png"))						return false;
	if (!bludgeon.loadFromFile("../assets/weapons/clubs/bludgeon.png"))					return false;
	if (!club.loadFromFile("../assets/weapons/clubs/club.png"))							return false;
	if (!cudgel.loadFromFile("../assets/weapons/clubs/cudgel.png"))						return false;
	if (!mace.loadFromFile("../assets/weapons/clubs/mace.png"))							return false;
		
	if (!halberd.loadFromFile("../assets/weapons/spears/halberd.png"))					return false;
	if (!pike.loadFromFile("../assets/weapons/spears/pike.png"))						return false;
	if (!pole.loadFromFile("../assets/weapons/spears/pole.png"))						return false;
	if (!sickle.loadFromFile("../assets/weapons/spears/sickle.png"))					return false;
	if (!spear.loadFromFile("../assets/weapons/spears/spear.png"))						return false;

	if (!cleaver.loadFromFile("../assets/weapons/swords/cleaver.png"))					return false;
	if (!cutlass.loadFromFile("../assets/weapons/swords/cutlass.png"))					return false;
	if (!foil.loadFromFile("../assets/weapons/swords/foil.png"))						return false;
	if (!rapier.loadFromFile("../assets/weapons/swords/rapier.png"))					return false;
	if (!sabre.loadFromFile("../assets/weapons/swords/sabre.png"))						return false;
	if (!scimitar.loadFromFile("../assets/weapons/swords/scimitar.png"))				return false;
	if (!sword.loadFromFile("../assets/weapons/swords/sword.png"))						return false;
	if (!sword_broad.loadFromFile("../assets/weapons/swords/sword_broad.png"))			return false;
	if (!sword_great.loadFromFile("../assets/weapons/swords/sword_great.png"))			return false;
	if (!sword_king.loadFromFile("../assets/weapons/swords/sword_king.png"))			return false;

	// shields
	if (!buckler_wooden.loadFromFile("../assets/weapons/shields/buckler_wooden.png"))	return false;
	if (!buckler_iron.loadFromFile("../assets/weapons/shields/buckler_iron.png"))		return false;
	if (!buckler_steel.loadFromFile("../assets/weapons/shields/buckler_steel.png"))		return false;
	if (!buckler_eternal.loadFromFile("../assets/weapons/shields/buckler_eternal.png")) return false;

	if (!heater_wooden.loadFromFile("../assets/weapons/shields/heater_wooden.png"))		return false;
	if (!heater_iron.loadFromFile("../assets/weapons/shields/heater_iron.png"))			return false;

	if (!kite_wooden.loadFromFile("../assets/weapons/shields/kite_wooden.png"))			return false;
	if (!kite_iron.loadFromFile("../assets/weapons/shields/kite_iron.png"))				return false;

	if (!wankel_wooden.loadFromFile("../assets/weapons/shields/wankel_wooden.png"))		return false;
	if (!wankel_iron.loadFromFile("../assets/weapons/shields/wankel_iron.png"))			return false;

	return true;

#endif

	// release resource file paths

	// data
	mapDataFilePath = "assets/world/mapdata.txt";

	// fonts
	if (!font.loadFromFile("assets/fonts/arial.ttf"))									return false;
	if (!notificationFont.loadFromFile("assets/fonts/notificationfont.ttf"))			return false;

	// sounds
	if (!music.openFromFile("assets/sounds/stardew.wav"))								return false;
	if (!notificationSound.loadFromFile("assets/sounds/notificationsound.wav"))			return false;

	// textures
	if (!notification.loadFromFile("assets/textures/notificationboard.png"))			return false;
	if (!objSheet.loadFromFile("../assets/textures/chip.png"))							return false;
	if (!ocean.loadFromFile("assets/textures/ocean.png"))								return false;

	// characters
	if (!player.loadFromFile("assets/characters/player.png"))							return false;

	// weapons
	if (!battleaxe.loadFromFile("assets/weapons/axes/battleaxe.png"))					return false;
	if (!lumberjack.loadFromFile("assets/weapons/axes/lumberjack.png"))					return false;
	if (!one_handed.loadFromFile("assets/weapons/axes/one_handed.png"))					return false;
	if (!tomahawk.loadFromFile("assets/weapons/axes/tomahawk.png"))						return false;
	if (!wedge.loadFromFile("assets/weapons/axes/wedge.png"))							return false;

	if (!baton.loadFromFile("assets/weapons/clubs/baton.png"))							return false;
	if (!bludgeon.loadFromFile("assets/weapons/clubs/bludgeon.png"))					return false;
	if (!club.loadFromFile("assets/weapons/clubs/club.png"))							return false;
	if (!cudgel.loadFromFile("assets/weapons/clubs/cudgel.png"))						return false;
	if (!mace.loadFromFile("assets/weapons/clubs/mace.png"))							return false;

	if (!halberd.loadFromFile("assets/weapons/spears/halberd.png"))						return false;
	if (!pike.loadFromFile("assets/weapons/spears/pike.png"))							return false;
	if (!pole.loadFromFile("assets/weapons/spears/pole.png"))							return false;
	if (!sickle.loadFromFile("assets/weapons/spears/sickle.png"))						return false;
	if (!spear.loadFromFile("assets/weapons/spears/spear.png"))							return false;

	if (!cleaver.loadFromFile("assets/weapons/swords/cleaver.png"))						return false;
	if (!cutlass.loadFromFile("assets/weapons/swords/cutlass.png"))						return false;
	if (!foil.loadFromFile("assets/weapons/swords/foil.png"))							return false;
	if (!rapier.loadFromFile("assets/weapons/swords/rapier.png"))						return false;
	if (!sabre.loadFromFile("assets/weapons/swords/sabre.png"))							return false;
	if (!scimitar.loadFromFile("assets/weapons/swords/scimitar.png"))					return false;
	if (!sword.loadFromFile("assets/weapons/swords/sword.png"))							return false;
	if (!sword_broad.loadFromFile("assets/weapons/swords/sword_broad.png"))				return false;
	if (!sword_great.loadFromFile("assets/weapons/swords/sword_great.png"))				return false;
	if (!sword_king.loadFromFile("assets/weapons/swords/sword_king.png"))				return false;

	// shields
	if (!buckler_wooden.loadFromFile("assets/weapons/shields/buckler_wooden.png"))		return false;
	if (!buckler_iron.loadFromFile("assets/weapons/shields/buckler_iron.png"))			return false;
	if (!buckler_steel.loadFromFile("assets/weapons/shields/buckler_steel.png"))		return false;
	if (!buckler_eternal.loadFromFile("assets/weapons/shields/buckler_eternal.png"))	return false;

	if (!heater_wooden.loadFromFile("assets/weapons/shields/heater_wooden.png"))		return false;
	if (!heater_iron.loadFromFile("assets/weapons/shields/heater_iron.png"))			return false;

	if (!kite_wooden.loadFromFile("assets/weapons/shields/kite_wooden.png"))			return false;
	if (!kite_iron.loadFromFile("assets/weapons/shields/kite_iron.png"))				return false;

	if (!wankel_wooden.loadFromFile("assets/weapons/shields/wankel_wooden.png"))		return false;
	if (!wankel_iron.loadFromFile("assets/weapons/shields/wankel_iron.png"))			return false;

	return true;
}

bool Resources::FillPacks()
{
	// weapons
	weapons.push_back(battleaxe);
	weapons.push_back(lumberjack);
	weapons.push_back(one_handed);
	weapons.push_back(tomahawk);
	weapons.push_back(wedge);
	
	weapons.push_back(baton);
	weapons.push_back(bludgeon);
	weapons.push_back(club);
	weapons.push_back(cudgel);
	weapons.push_back(mace);

	weapons.push_back(halberd);
	weapons.push_back(pike);
	weapons.push_back(pole);
	weapons.push_back(sickle);
	weapons.push_back(spear);

	weapons.push_back(cleaver);
	weapons.push_back(cutlass);
	weapons.push_back(foil);
	weapons.push_back(rapier);
	weapons.push_back(sabre);
	weapons.push_back(scimitar);
	weapons.push_back(sword);
	weapons.push_back(sword_broad);
	weapons.push_back(sword_great);
	weapons.push_back(sword_king);

	// shields

	shields.push_back(buckler_wooden);
	shields.push_back(buckler_iron);
	shields.push_back(buckler_steel);
	shields.push_back(buckler_eternal);

	shields.push_back(heater_wooden);
	shields.push_back(heater_iron);

	shields.push_back(kite_wooden);
	shields.push_back(kite_iron);

	shields.push_back(wankel_wooden);
	shields.push_back(wankel_iron);

	// plants

	// containers
	

	return true;
}