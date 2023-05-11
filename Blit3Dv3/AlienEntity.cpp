#include "AlienEntity.h"

extern b2World* world;
extern std::vector<Sprite*> blockSprites;
extern std::vector<Sprite*> blockElementList;
extern std::vector<Sprite*> blockElementMidlyDamagedList;
extern std::vector<Sprite*> blockElementHeavyDamagedList;

AlienEntity* MakeAlien(AlienShape atype,int spriteOffset, b2Vec2 pixelCoords,
	float angleInDegrees, int maximumHP) 
{
	AlienEntity* alienEntity = new AlienEntity();
	alienEntity->alienShape = atype;
	//alienEntity->materialType = mtype;

	b2BodyDef bodyDef;

	bodyDef.type = b2_dynamicBody; //make it a dynamic body i.e. one moved by physics
	bodyDef.position = Pixels2Physics(pixelCoords); //set its position in the world
	bodyDef.angle = deg2rad(angleInDegrees);

	bodyDef.angularDamping = 1.8f;

	bodyDef.userData.pointer = reinterpret_cast<uintptr_t> (alienEntity);

	alienEntity->body = world->CreateBody(&bodyDef); //create the body and add it to the world

	b2FixtureDef fixtureDef;

	// Define a shape for our body.
	b2PolygonShape polygon;
	b2CircleShape circle;
	// This defines a triangle in CCW order.
	b2Vec2 vertices[4];
	int32 count = 0;
	switch (atype)
	{
	case AlienShape::SHAPE0:
	case AlienShape::SHAPE2:
	case AlienShape::SHAPE3:
	case AlienShape::SHAPE4:
	case AlienShape::SHAPE5:
	{

		// SMALL_SQUARE is 70*70 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-35 / PTM_RATIO, 35 / PTM_RATIO);
		vertices[1].Set(-35 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[2].Set(35 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[3].Set(35 / PTM_RATIO, 35 / PTM_RATIO);
		count = 4;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
	break;

	case AlienShape::SHAPE1:
	case AlienShape::SHAPE6:
	case AlienShape::SHAPE7:
	case AlienShape::SHAPE8:
	case AlienShape::SHAPE9:
		//Circle doesn't need to be centered
		circle.m_radius = 70.f / (2 * PTM_RATIO);
		fixtureDef.shape = &circle;
		break;
	
	default:
		assert(false);
	}//end switch(btype)


	fixtureDef.density = 0.1f;		//1.1f
	fixtureDef.restitution = 0.05;	//0.05
	fixtureDef.friction = 0.2;		//0.1


	alienEntity->body->CreateFixture(&fixtureDef);

		int numSpritesToSkip = (int)atype + (spriteOffset * 10); //10 sprites per shape

	//add sprites
	alienEntity->sprite = blockElementList[numSpritesToSkip];//numSpritesToSkip
	alienEntity->spriteList.push_back(blockElementMidlyDamagedList[numSpritesToSkip]);
	alienEntity->spriteList.push_back(blockElementHeavyDamagedList[numSpritesToSkip]);
	//alienEntity->spriteList.push_back(blockElementHeavyDamagedList[numSpritesToSkip]);

	alienEntity->maxHP = alienEntity->hp = maximumHP;

	return alienEntity;
}

void LoadAlienEntity(std::string fileName, std::vector<Entity*> &alienEntityList) {

	//clear the current elementList
	for (auto B : alienEntityList) delete B;
	alienEntityList.clear();

	//open files
	std::ifstream myfile;

	myfile.open(fileName);
	//assert(!myfileNP.open(fileName));

	if (myfile.is_open())
	{
		//read in # of Elements
		int elementNum = 0;
		myfile >> elementNum;

		//read in each element
		for (; elementNum > 0; --elementNum)
		{
			//make an Element*
			AlienEntity* B = new AlienEntity();
			int offsetA = 0, offsetB = 0, x = 0, y = 0, angle = 0, hp = 0;
			myfile >> offsetA;
			myfile >> offsetB;
			myfile >> x;
			myfile >> y;
			myfile >> angle;
			myfile >> hp;

			B = MakeAlien((AlienShape)offsetA,offsetB, b2Vec2(x, y), angle, hp);
			alienEntityList.push_back(B);

		}

		myfile.close();
	}
	else assert(false);
}

