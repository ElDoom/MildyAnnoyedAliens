#pragma once

#include "Entity.h"

enum class AlienShape { SHAPE0, SHAPE1, SHAPE2, SHAPE3, SHAPE4, SHAPE5, SHAPE6, SHAPE7, SHAPE8, SHAPE9 };

class AlienEntity : public Entity
{
public:
	AlienShape alienShape;
	int spriteOffset = 5;
	int hp;
	int maxHP;
	std::vector<Sprite*> spriteList;

	AlienEntity()
	{
		typeID = ENTITYALIEN;
		alienShape = AlienShape::SHAPE0;
		spriteOffset = 5;
		maxHP = hp = 100;
	}

	//Damage() returns true if we should kill this object
	bool Damage(int damage)
	{
		hp -= damage;
		if (hp < 1) return true;
		if (hp < maxHP / 3) sprite = spriteList[1];
		else if (hp < maxHP * 0.66) sprite = spriteList[0];

		return false;
	}
};

AlienEntity* MakeAlien(AlienShape atype, b2Vec2 pixelCoords,
	float angleInDegrees, int maximumHP);

void LoadAlienEntity(std::string fileName, std::vector<Entity*> &alienEntityList);