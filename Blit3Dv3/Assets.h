#pragma once
extern std::vector<Sprite*> blockElementList;
extern std::vector<Sprite*> blockElementMidlyDamagedList;
extern std::vector<Sprite*> blockElementHeavyDamagedList;
extern Sprite* blankFloorSprite;

extern std::vector<Sprite*> debrisList;

extern Sprite* cannonballSprite;
extern Sprite* cannonbarrelSprite;
extern Sprite* metersprite;
extern Sprite* groundSprite;
extern Sprite* cactusSprite;

extern Sprite* logo;
extern Sprite* logoGO;

void loadAssets() {
	blankFloorSprite = blit3D->MakeSprite(0, 0, 3840, 70, "Media\\LowerLevel.png");
	cannonballSprite = blit3D->MakeSprite(0, 0, 36, 36, "Media\\Cannonball.png");
	cannonbarrelSprite = blit3D->MakeSprite(0, 0, 440, 128, "Media\\barrel-h.png");
	metersprite = blit3D->MakeSprite(0, 0, 100, 100, "Media\\meter.png");
	logo = blit3D->MakeSprite(0, 0, 1920, 1080, "Media\\logo.png");
	logoGO = blit3D->MakeSprite(0, 0, 1920, 1080, "Media\\logoGO.png");
	//load debris sprites
	//WOOD debris
	debrisList.push_back(blit3D->MakeSprite(0, 57, 64, 55, "Media\\spritesheet_debris.png"));
	debrisList.push_back(blit3D->MakeSprite(0, 168, 64, 52, "Media\\spritesheet_debris.png"));
	debrisList.push_back(blit3D->MakeSprite(0, 446, 68, 51, "Media\\spritesheet_debris.png"));
	//DUMMY METAL debris
	debrisList.push_back(blit3D->MakeSprite(0, 57, 64, 55, "Media\\spritesheet_debris.png"));
	debrisList.push_back(blit3D->MakeSprite(0, 168, 64, 52, "Media\\spritesheet_debris.png"));
	debrisList.push_back(blit3D->MakeSprite(0, 446, 68, 51, "Media\\spritesheet_debris.png"));
	//ICE debris
	debrisList.push_back(blit3D->MakeSprite(0, 0, 64, 56, "Media\\spritesheet_debris.png"));
	debrisList.push_back(blit3D->MakeSprite(1, 271, 58, 53, "Media\\spritesheet_debris.png"));
	debrisList.push_back(blit3D->MakeSprite(0, 385, 56, 61, "Media\\spritesheet_debris.png"));

	//Wood Assets
	blockElementList.push_back(blit3D->MakeSprite(221, 721, 138, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 71, 218, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 631, 218, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 141, 138, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(571, 641, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 571, 138, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 221, 68, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 651, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 941, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementList.push_back(blit3D->MakeSprite(711, 711, 68, 218, "Media\\Spritesheet\\spritesheet_wood.png"));
	//Stone Assets
	blockElementList.push_back(blit3D->MakeSprite(221, 721, 138, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 71, 218, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 631, 218, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 141, 138, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(571, 641, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 571, 138, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 221, 68, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 651, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 941, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementList.push_back(blit3D->MakeSprite(711, 711, 68, 218, "Media\\Spritesheet\\spritesheet_stone.png"));
	//Metal Assets
	blockElementList.push_back(blit3D->MakeSprite(361, 791, 138, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 141, 218, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 701, 218, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 1, 138, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 641, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(361, 71, 138, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 651, 68, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(711, 291, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(711, 581, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 221, 68, 218, "Media\\Spritesheet\\spritesheet_metal.png"));
	//Glass Assets
	blockElementList.push_back(blit3D->MakeSprite(501, 71, 138, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 141, 218, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 1, 218, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(361, 511, 138, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(711, 711, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(441, 1, 138, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(781, 1, 68, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 861, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 791, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementList.push_back(blit3D->MakeSprite(711, 211, 68, 218, "Media\\Spritesheet\\spritesheet_glass.png"));

	//Explosives Assets
	blockElementList.push_back(blit3D->MakeSprite(501, 491, 138, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 141, 218, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(1, 701, 218, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(501, 351, 138, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(781, 71, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(361, 511, 138, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 501, 68, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 431, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(641, 921, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementList.push_back(blit3D->MakeSprite(711, 511, 68, 218, "Media\\Spritesheet\\spritesheet_explosive.png"));

	//Alien Assets
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(70, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(140, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(210, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(280, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(70, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(210, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(280, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));
	blockElementList.push_back(blit3D->MakeSprite(280, 140, 70, 70, "Media\\Spritesheet\\spritesheet_aliens.png"));

	//Visual Assets
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 70, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 140, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(70, 0, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(70, 140, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(140, 0, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(140, 70, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(140, 140, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(280, 140, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(420, 70, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));

	//Floor Assets
	blockElementList.push_back(blit3D->MakeSprite(210, 0, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(210, 70, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(210, 140, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(280, 70, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(70, 140, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(280, 0, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(350, 0, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(350, 70, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(350, 140, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));
	blockElementList.push_back(blit3D->MakeSprite(420, 0, 70, 70, "Media\\Spritesheet\\spritesheet_tiles.png"));

	//Cloud Assets
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 174, 157, "Media\\cumulus-big1.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 190, 118, "Media\\cumulus-big2.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 238, 128, "Media\\cumulus-big3.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 512, 211, "Media\\cumulus-huge.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 54, 43, "Media\\cumulus-small1.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 76, 51, "Media\\cumulus-small2.png"));
	blockElementList.push_back(blit3D->MakeSprite(0, 0, 64, 41, "Media\\cumulus-small3.png"));
	blockElementList.push_back(blit3D->MakeSprite(12, 12, 101, 28, "Media\\cumulus-tiny.png"));
	blockElementList.push_back(blit3D->MakeSprite(12, 55, 38, 16, "Media\\cumulus-tiny.png"));
	blockElementList.push_back(blit3D->MakeSprite(9, 85, 107, 22, "Media\\cumulus-tiny.png"));

	//Midly Damaged
	//Wood Assets
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(361, 501, 138, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 281, 218, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 840, 218, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(360, 360, 138, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 361, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 281, 138, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 431, 68, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 571, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(641, 581, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(641, 1, 68, 218, "Media\\Spritesheet\\spritesheet_wood.png"));
	//Stone Assets
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(361, 501, 138, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 281, 218, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 840, 218, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(360, 360, 138, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 361, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 281, 138, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 431, 68, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 571, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(641, 581, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(641, 1, 68, 218, "Media\\Spritesheet\\spritesheet_stone.png"));
	//Metal Assets
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(221, 351, 138, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 351, 218, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 211, 218, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 431, 138, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 861, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 571, 138, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(571, 851, 68, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 931, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 221, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 361, 68, 218, "Media\\Spritesheet\\spritesheet_metal.png"));
	//Glass Assets
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 351, 138, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 491, 218, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 351, 218, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(361, 791, 138, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 141, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 281, 138, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 1, 68, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 431, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(641, 361, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 641, 68, 218, "Media\\Spritesheet\\spritesheet_glass.png"));

	//Explosives Assets
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(361, 941, 138, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 491, 218, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(1, 841, 218, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 141, 138, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 801, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(501, 561, 138, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(641, 1, 68, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 941, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(641, 851, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(711, 221, 68, 218, "Media\\Spritesheet\\spritesheet_explosive.png"));

	//Alien Assets
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(0, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(0, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(70, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(140, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(210, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(280, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(70, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(210, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(280, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));
	blockElementMidlyDamagedList.push_back(blit3D->MakeSprite(280, 140, 70, 70, "Media\\Spritesheet\\spritesheet_aliensMD.png"));

	//Heavy Damaged
	//Wood Assets
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 291, 138, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 1, 218, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 351, 218, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 361, 138, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(571, 711, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 791, 138, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(781, 1, 68, 138, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(501, 711, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(571, 921, 68, 68, "Media\\Spritesheet\\spritesheet_wood.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 361, 68, 218, "Media\\Spritesheet\\spritesheet_wood.png"));
	//Stone Assets
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 291, 138, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 1, 218, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 351, 218, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 361, 138, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(571, 711, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 791, 138, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(781, 1, 68, 138, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(501, 711, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(571, 921, 68, 68, "Media\\Spritesheet\\spritesheet_stone.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 361, 68, 218, "Media\\Spritesheet\\spritesheet_stone.png"));
	//Metal Assets
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 421, 138, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 841, 218, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 421, 218, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 71, 138, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(501, 781, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 211, 138, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 441, 68, 138, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(501, 711, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(571, 641, 68, 68, "Media\\Spritesheet\\spritesheet_metal.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 791, 68, 218, "Media\\Spritesheet\\spritesheet_metal.png"));
	//Glass Assets
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 861, 138, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 561, 218, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 211, 218, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 361, 138, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(571, 781, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 71, 138, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 1, 68, 138, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(501, 931, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(711, 571, 68, 68, "Media\\Spritesheet\\spritesheet_glass.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 431, 68, 218, "Media\\Spritesheet\\spritesheet_glass.png"));

	//Explosives Assets
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 501, 138, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 71, 218, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(1, 211, 218, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 291, 138, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 781, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(221, 431, 138, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 641, 68, 138, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(571, 911, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(641, 361, 68, 68, "Media\\Spritesheet\\spritesheet_explosive.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(711, 1 , 68, 218, "Media\\Spritesheet\\spritesheet_explosive.png"));

	//Alien Assets
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(0, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(0, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(70, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(140, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(210, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(280, 0, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(70, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(210, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(280, 70, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));
	blockElementHeavyDamagedList.push_back(blit3D->MakeSprite(280, 140, 70, 70, "Media\\Spritesheet\\spritesheet_aliensHD.png"));

}