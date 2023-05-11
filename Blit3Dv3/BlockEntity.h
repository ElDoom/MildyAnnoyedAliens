#pragma once

#include "Entity.h"


//enum class ElementEnum {BLOCK = 0, ALIEN, VISUAL, FLOOR, END };
//enum class BlockType { LARGE_TRIANGLE, RECTANGLE, BIG_RECT, SQUARE, SMALL_CIRCLE, SMALL_RECT, SMALL_RECT2, SMALL_TRIANGLE, SMALL_SQUARE, RECTANGLE2, END };
//enum class MaterialType { WOOD = 0, STONE, METAL, ICE, EXPLOSIVE, END };

enum class BlockType { LARGE_TRIANGLE, RECTANGLE, BIG_RECT, SQUARE, SMALL_CIRCLE, SMALL_RECT, 
	SMALL_RECT2, SMALL_TRIANGLE, SMALL_SQUARE, RECTANGLE2, END };

enum class MaterialType { WOOD = 0, STONE, METAL, ICE, EXPLOSIVE, END };

class BlockEntity : public Entity
{
public:
	BlockType blockType;
	MaterialType materialType;
	int hp;
	int maxHP;
	std::vector<Sprite *> spriteList;

	BlockEntity()
	{
		typeID = ENTITYBLOCK;
		blockType = BlockType::LARGE_TRIANGLE;
		materialType = MaterialType::WOOD;
		maxHP = hp = 100;
	}

	//Damage() returns true if we should kill this object
	bool Damage(int damage)
	{
		hp -= damage;
		if (hp < 1) return true;
		if (hp < maxHP/3) sprite = spriteList[1];
		else if (hp < maxHP * 0.66) sprite = spriteList[0];

		return false;
	}
};

BlockEntity * MakeBlock(BlockType btype, MaterialType mtype, b2Vec2 pixelCoords, 
	float angleInDegrees, int maximumHP);

void LoadBlockEntity(std::string fileName, std::vector<Entity*> &blockEntityList);