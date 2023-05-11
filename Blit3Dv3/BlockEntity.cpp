#include "BlockEntity.h"

extern b2World *world;
extern std::vector<Sprite*> blockSprites;
extern std::vector<Sprite*> blockElementList;
extern std::vector<Sprite*> blockElementMidlyDamagedList;
extern std::vector<Sprite*> blockElementHeavyDamagedList;

BlockEntity * MakeBlock(BlockType btype, MaterialType mtype, b2Vec2 pixelCoords,
	float angleInDegrees, int maximumHP)
{
	BlockEntity * blockEntity = new BlockEntity();
	blockEntity->blockType = btype;
	blockEntity->materialType = mtype;

	b2BodyDef bodyDef;
	
	bodyDef.type = b2_dynamicBody; //make it a dynamic body i.e. one moved by physics
	bodyDef.position = Pixels2Physics(pixelCoords); //set its position in the world
	bodyDef.angle = deg2rad(angleInDegrees);

	bodyDef.angularDamping = 1.8f;

	bodyDef.userData.pointer = reinterpret_cast<uintptr_t> (blockEntity);

	blockEntity->body = world->CreateBody(&bodyDef); //create the body and add it to the world

	b2FixtureDef fixtureDef;

	// Define a shape for our body.
	b2PolygonShape polygon;
	b2CircleShape circle;
	// This defines a triangle in CCW order.
	b2Vec2 vertices[4];
	int32 count = 0;
	switch (btype)
	{
	case BlockType::LARGE_TRIANGLE:
	{
		
		// LARGE_TRIANGLE is 140*70 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(0/PTM_RATIO,35/PTM_RATIO);
		vertices[1].Set(-70 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[2].Set(70 / PTM_RATIO, -35 / PTM_RATIO);
		count = 3;		

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
		break;
	case BlockType::RECTANGLE:
	{

		// RECTANGLE is 220*70 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-110 / PTM_RATIO, 35 / PTM_RATIO);
		vertices[1].Set(-110 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[2].Set(110 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[3].Set(110 / PTM_RATIO, 35 / PTM_RATIO);
		count = 4;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
		break;
	case BlockType::BIG_RECT:
	{

		// BIG_RECT is 220*140 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-110 / PTM_RATIO, 70 / PTM_RATIO);
		vertices[1].Set(-110 / PTM_RATIO, -70 / PTM_RATIO);
		vertices[2].Set(110 / PTM_RATIO, -70 / PTM_RATIO);
		vertices[3].Set(110 / PTM_RATIO, 70 / PTM_RATIO);
		count = 4;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
		break;
	case BlockType::SQUARE:
	{

		// SQUARE is 140*140 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-70 / PTM_RATIO, 70 / PTM_RATIO);
		vertices[1].Set(-70 / PTM_RATIO, -70 / PTM_RATIO);
		vertices[2].Set(70 / PTM_RATIO, -70 / PTM_RATIO);
		vertices[3].Set(70 / PTM_RATIO, 70 / PTM_RATIO);
		count = 4;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
		break;
	case BlockType::SMALL_CIRCLE:
		//Circle doesn't need to be centered
		circle.m_radius = 70.f / (2 * PTM_RATIO);
		fixtureDef.shape = &circle;
		break;
	case BlockType::SMALL_RECT:
	{

		// SMALL_RECT is 140*70 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-70 / PTM_RATIO, 35 / PTM_RATIO);
		vertices[1].Set(-70 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[2].Set(70 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[3].Set(70 / PTM_RATIO, 35 / PTM_RATIO);
		count = 4;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
		break;
	case BlockType::SMALL_RECT2:
	{

		// SMALL_RECT2 is 70*140 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-35 / PTM_RATIO, 70 / PTM_RATIO);
		vertices[1].Set(-35 / PTM_RATIO, -70 / PTM_RATIO);
		vertices[2].Set(35 / PTM_RATIO, -70 / PTM_RATIO);
		vertices[3].Set(35 / PTM_RATIO, 70 / PTM_RATIO);
		count = 4;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
	break;
	case BlockType::SMALL_TRIANGLE:
	{

		// SMALL_TRIANGLE is 70*70 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-35 / PTM_RATIO, 35 / PTM_RATIO);
		vertices[1].Set(-35 / PTM_RATIO, -35 / PTM_RATIO);
		vertices[2].Set(35 / PTM_RATIO, -35 / PTM_RATIO);
		//vertices[0].Set(-15 / PTM_RATIO, 55 / PTM_RATIO);
		//vertices[1].Set(-15 / PTM_RATIO, -15 / PTM_RATIO);
		//vertices[2].Set(55 / PTM_RATIO, -15 / PTM_RATIO);
		
		count = 3;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
		break;
	case BlockType::SMALL_SQUARE:
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
	case BlockType::RECTANGLE2:
	{

		// RECTANGLE2 is 70*220 and we are moving its centre to (0,0 coordinates)
		vertices[0].Set(-35 / PTM_RATIO, 110 / PTM_RATIO);
		vertices[1].Set(-35 / PTM_RATIO, -110 / PTM_RATIO);
		vertices[2].Set(35 / PTM_RATIO, -110 / PTM_RATIO);
		vertices[3].Set(35 / PTM_RATIO, 110 / PTM_RATIO);
		count = 4;

		polygon.Set(vertices, count);

		fixtureDef.shape = &polygon;
	}
	break;
	default:
		assert(false);
	}//end switch(btype)

	switch (mtype) //WOOD = 0, STONE, METAL, ICE, EXPLOSIVE,
	{
	case MaterialType::WOOD:
		fixtureDef.density = 0.4f;		//0.8		//The density, usually in kg/m^2.
		fixtureDef.restitution = 0.05;	//0.05		//The restitution(elasticity) usually in the range[0, 1].
		fixtureDef.friction = 0.6;		//0.8		//The friction coefficient, usually in the range [0,1].
		break;
	case MaterialType::STONE:
		fixtureDef.density = 0.6f;
		fixtureDef.restitution = 0.05;
		fixtureDef.friction = 0.8;
		break;
	case MaterialType::METAL:
		fixtureDef.density = 0.8f;
		fixtureDef.restitution = 0.01;
		fixtureDef.friction = 0.9;
		break;
	case MaterialType::ICE:
		fixtureDef.density = 0.2f;		//1.1f
		fixtureDef.restitution = 0.05;	//0.05
		fixtureDef.friction = 0.1;		//0.1
		break;
	case MaterialType::EXPLOSIVE:
		fixtureDef.density = 0.8f;
		fixtureDef.restitution = 0.01;
		fixtureDef.friction = 0.9;
		break;

	default:
		assert(false);
	}//end switch(mtype)

	blockEntity->body->CreateFixture(&fixtureDef);

	//int numBlockTypesToSkip = (int) btype;
	//int numMaterials = (int) MaterialType::END;
	int numSpritesToSkip = (int)btype + ((int)mtype * 10); //10 sprites per shape

	//add sprites
	blockEntity->sprite = blockElementList[numSpritesToSkip];
	blockEntity->spriteList.push_back(blockElementMidlyDamagedList[numSpritesToSkip]);
	blockEntity->spriteList.push_back(blockElementHeavyDamagedList[numSpritesToSkip]);

	blockEntity->maxHP = blockEntity->hp = maximumHP;

	return blockEntity;	
}

void LoadBlockEntity(std::string fileName, std::vector<Entity*> &blockEntityList) {
	
	//clear the current elementList
	for (auto B : blockEntityList) delete B;
	blockEntityList.clear();

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
			BlockEntity* B = new BlockEntity();
			int totalOffset = 0, offsetA = 0, offsetB = 0, x = 0, y = 0, angle = 0, hp = 0;
			myfile >> offsetA;
			myfile >> offsetB;
			myfile >> x;
			myfile >> y;
			myfile >> angle;
			myfile >> hp;
			totalOffset = offsetA + (offsetB * 10);
			//std::cout << "Sprite number " << totalOffset << std::endl;
			//B->sprite = blockElementList[totalOffset];
			//B->position = b2Vec2(x, y);
			//B->body. = angle;
			B = MakeBlock((BlockType)offsetA, (MaterialType)offsetB, b2Vec2(x, y),angle,hp);
			blockEntityList.push_back(B);

		}

		myfile.close();
	}
	else assert(false);
}