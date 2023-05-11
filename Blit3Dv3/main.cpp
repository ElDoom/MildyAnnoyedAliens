/*
	"Angry Birds" style example
*/
#include "Blit3D.h"
#include <random>

#include "Box2d/Box2d.h"
#include "GroundEntity.h"
#include "ShotEntity.h"
#include "Particle.h"
#include "Physics.h"
#include "MyContactListener.h" 
#include "EdgeEntity.h"
#include "Cannon.h"
#include "Meter.h"
#include "Camera.h"
#include "BlockEntity.h"

#include "AlienEntity.h"
#include "Assets.h"
#include "GraphicElement.h"

#include "CollisionMask.h"

Blit3D *blit3D = NULL;

//memory leak detection
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

//GLOBAL DATA
b2World *world;
// Prepare for simulation. Typically we use a time step of 1/60 of a
// second (60Hz) and ~10 iterations. This provides a high quality simulation
// in most game scenarios.
int32 velocityIterations = 8;//8
int32 positionIterations = 3;
float timeStep = 1.f / 60.f; //one 60th of a second
float elapsedTime = 0; //used for calculating time passed
float settleTime = 0;

//contact listener to handle collisions between important objects
MyContactListener *contactListener;

enum GameState { START, PLAYING, SETTLING, GAMEOVER};
GameState gameState =GameState::START;
bool attachedShot = true; //is the ball ready to be launched from the paddle?
int lives = 15;
int points = 0;


std::vector<Entity *> blockEntityList;	//bricks go here

std::vector<Entity *> alienEntityList;	//aliens everywhere

std::vector<Entity *> shotEntityList;	//track the balls seperately from everything else
std::vector<Entity *> entityList;		//other entities in our game go here
std::vector<Entity *> deadEntityList;	//dead entities

std::vector<Particle *> particleList;

std::vector<GraphicElement*> elementList;

Cannon cannon;

bool fireShotNow = false;
bool followingShot = false; //is the camera tracking the shot?

Meter meter;

Camera2D *camera; //pans the view

//Sprites from example
Sprite* cannonballSprite = NULL;
Sprite* cannonbarrelSprite = NULL;
Sprite* metersprite = NULL;
Sprite* groundSprite = NULL;
Sprite* cactusSprite = NULL;
Sprite* logo = NULL;
Sprite* logoGO = NULL;
std::vector<Sprite *> blockSprites;
std::vector<Sprite *> debrisList;
std::vector<Sprite *> cloudList;

//Sprites from level editor
std::vector<Sprite*> blockElementList;
std::vector<Sprite*> blockElementMidlyDamagedList;
std::vector<Sprite*> blockElementHeavyDamagedList;
Sprite* blankFloorSprite;

std::mt19937 rng;

AngelcodeFont* caviar57font = NULL;

void generateLevel() {
	if (!blockEntityList.empty()) blockEntityList.clear();
	if (!alienEntityList.empty()) alienEntityList.clear();
	if (!shotEntityList.empty()) shotEntityList.clear();
	if (!entityList.empty()) entityList.clear();
	if (!deadEntityList.empty()) deadEntityList.clear();
	if (!particleList.empty()) particleList.clear();
	LoadGraphicElements("Media\\NPlevel.txt", elementList);
	LoadBlockEntity("Media\\level.txt", blockEntityList);
	LoadAlienEntity("Media\\ALIENSlevel.txt", alienEntityList);
}

//ensures that entities are only added ONCE to the deadEntityList
void AddToDeadList(Entity *e)
{
	bool unique = true;

	for (auto ent : deadEntityList)
	{
		if (ent == e)
		{
			unique = false;
			break;
		}
	}

	if (unique) deadEntityList.push_back(e);
}


//Random for particles
std::uniform_real_distribution<float> randomCircle(0, 360);
std::uniform_real_distribution<float> randomRotationSpeed(-90.f, 90.f);
std::uniform_real_distribution<float> randomSpeed(0.f, 200.f);
std::uniform_real_distribution<float> randomSizeStart(0.1f, 0.5f);
std::uniform_real_distribution<float> randomSizeEnd(0.05f, 0.15f);
std::uniform_int_distribution<int> randomZeroToTwo(0,2);

//Function that applies damage etc when a block collides with anything
void BlockCollide(Entity *A, float maxImpulseAB)
{
	BlockEntity *blockEntity = (BlockEntity *)A;
	//damage?
	if (maxImpulseAB > 0.5f) //cutoff for no damage //high more force wo doing damage
	{
		//apply some damage
		if (blockEntity->Damage((int)(maxImpulseAB *30.f)))
		{
			//Damage() returned true, need to kill this block
			AddToDeadList(A);
			points = points + blockEntity->maxHP;
			//spawn particles here
			//debrisList
			for (int particleCount = 0; particleCount < 10; ++particleCount)
			{

				Particle *p = new Particle();
				p->coords = Physics2Pixels(A->body->GetPosition());
				p->angle = randomCircle(rng);
				p->direction = deg2vec(randomCircle(rng));
				p->rotationSpeed = randomRotationSpeed(rng);
				p->startingSpeed = randomSpeed(rng);
				p->targetSpeed = randomSpeed(rng);
				p->totalTimeToLive = 0.3f;

				p->startingScaleX = randomSizeStart(rng);
				p->startingScaleY = randomSizeStart(rng);
				p->targetScaleX = randomSizeEnd(rng);
				p->targetScaleY = randomSizeEnd(rng);

				p->spriteList.push_back(debrisList[randomZeroToTwo(rng) +  3]);//+ ((int)blockEntity->materialType) * 3]
				particleList.push_back(p);
			}
		}
	}
}

void AllienCollide(Entity* A, float maxImpulseAB)
{
	AlienEntity* alienEntity = (AlienEntity*)A;
	//damage?
	if (maxImpulseAB > 0.3f) //cutoff for no damage //high more force wo doing damage
	{
		//apply some damage
		if (alienEntity->Damage((int)(maxImpulseAB * 30.f)))
		{
			//Damage() returned true, need to kill this block
			AddToDeadList(A);
			points = points + (alienEntity->maxHP*3);
			//aliensLeft--;
			//spawn particles here
			//debrisList
			for (int particleCount = 0; particleCount < 10; ++particleCount)
			{

				Particle* p = new Particle();
				p->coords = Physics2Pixels(A->body->GetPosition());
				p->angle = randomCircle(rng);
				p->direction = deg2vec(randomCircle(rng));
				p->rotationSpeed = randomRotationSpeed(rng);
				p->startingSpeed = randomSpeed(rng);
				p->targetSpeed = randomSpeed(rng);
				p->totalTimeToLive = 0.3f;

				p->startingScaleX = randomSizeStart(rng);
				p->startingScaleY = randomSizeStart(rng);
				p->targetScaleX = randomSizeEnd(rng);
				p->targetScaleY = randomSizeEnd(rng);

				p->spriteList.push_back(blockElementList[randomZeroToTwo(rng) + 50]);//+ ((int)blockEntity->materialType) * 3]
				particleList.push_back(p);
			}
		}
	}
}

void Init()
{
	//seed our rng
	std::random_device rd;
	rng.seed(rd());

	blit3D->ShowCursor(false);

	//make a camera
	camera = new Camera2D();

	//set it's valid pan area
	camera->minX = blit3D->screenWidth / 2;
	camera->minY = blit3D->screenHeight / 2;
	camera->maxX = blit3D->screenWidth * 2 - blit3D->screenWidth/2;
	camera->maxY = blit3D->screenHeight / 2 + 400;

	camera->PanTo(blit3D->screenWidth / 2, blit3D->screenHeight / 2);

	//load the sprites
	loadAssets();

	caviar57font = blit3D->MakeAngelcodeFontFromBinary32("Media\\CaviarDreams57.bin");

	cannon.sprite = cannonbarrelSprite;
	cannon.positionPixels = b2Vec2(100, 150);
	
	meter.sprite = metersprite;
	meter.positionPixels = cannon.positionPixels;

	
	
	// Define the gravity vector.
	b2Vec2 gravity(0.f, -9.8f);

	// Construct a world object, which will hold and simulate the rigid bodies.
	world = new b2World(gravity);
	//world->SetGravity(gravity); <-can call this to change gravity at any time
	world->SetAllowSleeping(true); //set true to allow the physics engine to 'sleep" objects that stop moving

								   //_________GROUND OBJECT_____________
								   //make an entity for the ground
	GroundEntity *groundEntity = new GroundEntity();

	//A bodyDef for the ground
	b2BodyDef groundBodyDef;
	// Define the ground body.
	groundBodyDef.position.Set(0, 0);

	//add the userdata
	groundBodyDef.userData.pointer = reinterpret_cast<uintptr_t>(groundEntity);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundEntity->body = world->CreateBody(&groundBodyDef);

	//an EdgeShape object, for the ground
	b2EdgeShape groundBox;

	// Define the ground as 1 edge shape at the bottom of the screen.
	b2FixtureDef boxShapeDef;

	boxShapeDef.shape = &groundBox;

	//collison masking
	boxShapeDef.filter.categoryBits = CMASK_GROUND;  //this is the ground
	boxShapeDef.filter.maskBits = CMASK_SHOT | CMASK_BLOCK | CMASK_ALIEN;		//it collides wth balls and powerups

																				//bottom
	groundBox.SetTwoSided(b2Vec2(0, 70 / PTM_RATIO), b2Vec2(blit3D->screenWidth * 2 / PTM_RATIO, 70 / PTM_RATIO));
	//Create the fixture
	groundEntity->body->CreateFixture(&boxShapeDef);
	
	//add to the entity list
	//groundEntity = defineGroudEntity(); //if time left do this pls
	entityList.push_back(groundEntity);

	//now make the other 3 edges of the screen on a seperate entity/body
	EdgeEntity * edgeEntity = new EdgeEntity();

	groundBodyDef.userData.pointer = reinterpret_cast<uintptr_t>(edgeEntity);
	edgeEntity->body = world->CreateBody(&groundBodyDef);

	boxShapeDef.filter.categoryBits = CMASK_EDGES;  //this is the ground
	boxShapeDef.filter.maskBits = CMASK_SHOT | CMASK_BLOCK | CMASK_ALIEN;		//it collides wth balls

																				//left
	groundBox.SetTwoSided(b2Vec2(0, blit3D->screenHeight * 2 / PTM_RATIO), b2Vec2(0, 70 / PTM_RATIO));
	edgeEntity->body->CreateFixture(&boxShapeDef);

	//top
	groundBox.SetTwoSided(b2Vec2(0, blit3D->screenHeight * 2 / PTM_RATIO),
		b2Vec2(blit3D->screenWidth * 2 / PTM_RATIO, blit3D->screenHeight * 2 / PTM_RATIO));
	edgeEntity->body->CreateFixture(&boxShapeDef);

	//right
	groundBox.SetTwoSided(b2Vec2(blit3D->screenWidth * 2 / PTM_RATIO, 70 / PTM_RATIO),
		b2Vec2(blit3D->screenWidth * 2 / PTM_RATIO, blit3D->screenHeight * 2 / PTM_RATIO));
	edgeEntity->body->CreateFixture(&boxShapeDef);

	entityList.push_back(edgeEntity);

	// Create contact listener and use it to collect info about collisions
	contactListener = new MyContactListener();
	world->SetContactListener(contactListener);

	//LoadGraphicElements("Media\\NPlevel.txt",blockElementList, elementList);
	generateLevel();
	//LoadGraphicElements("Media\\NPlevel.txt", elementList);
	//LoadBlockEntity("Media\\level.txt", blockEntityList );
	//LoadAlienEntity("Media\\ALIENSlevel.txt", alienEntityList);
	//aliensLeft =  alienEntityList.size();
}

void DeInit(void)
{
	if (camera != NULL) delete camera;
	
	//delete all particles
	for (auto &p : particleList) delete p;
	particleList.clear();

	//delete all the entities
	for (auto &e : entityList) delete e;
	entityList.clear();

	for (auto& e : elementList) delete e;
	elementList.clear();

	for (auto &s : shotEntityList) delete s;
	shotEntityList.clear();

	for (auto &b : blockEntityList) delete b;
	blockEntityList.clear();

	for (auto& a : alienEntityList) delete a;
	alienEntityList.clear();

	//delete the contact listener
	delete contactListener;

	//Free all physics game data we allocated
	delete world;
	//any sprites still allocated are freed automatcally by the Blit3D object when we destroy it
}

void Update(double seconds)
{
	
	
	switch (gameState)
	{
	case SETTLING:
	{
		camera->Update((float)seconds);
		elapsedTime += seconds;
		while (elapsedTime >= timeStep)
		{
			//update the physics world
			world->Step(timeStep, velocityIterations, positionIterations);

			// Clear applied body forces. 
			world->ClearForces();

			settleTime += timeStep;
			elapsedTime -= timeStep;
		}

		if (settleTime > 3) gameState = PLAYING;
	}
	break;
	case PLAYING:
	{
		elapsedTime += seconds;
		
		if (fireShotNow)
		{

			fireShotNow = false;
			followingShot = true;

			
			if (lives > 0)
			{
				lives--;
				//fire a shot!
				ShotEntity *shot = MakeShot();
				b2Vec2 pos = Pixels2Physics(cannon.positionPixels);

				b2Vec2 dirCannon = Pixels2Physics(deg2vec(cannon.angle, 220));

				shot->body->SetTransform(pos + dirCannon, 0);

				b2Vec2 dir = deg2vec(cannon.angle, meter.scale * 8  + 1);//meter.scale * 3(other bigger or short) + 1

				shot->body->ApplyLinearImpulse(dir, shot->body->GetPosition(), true);
				shotEntityList.push_back(shot);

			}
		}

		//don't apply physics unless at least a timestep worth of time has passed
		while (elapsedTime >= timeStep)
		{
			//update the physics world
			world->Step(timeStep, velocityIterations, positionIterations);	//timeStep, velocityIterations, positionIterations

			// Clear applied body forces. 
			world->ClearForces();

			elapsedTime -= timeStep;

			//update game logic/animation
			for (auto &e : entityList) e->Update(timeStep);
			for (auto &b : shotEntityList) b->Update(timeStep);
			for (auto &b : blockEntityList) b->Update(timeStep);
			for (auto & a : alienEntityList) a->Update(timeStep);

			//update shot meter
			meter.Update(timeStep);

			//update cannon
			cannon.Update(timeStep);

			//update camera
			if (followingShot)
			{
				//make sure there is a shot to follow
				int size = shotEntityList.size();
				if (size > 0)
				{
					//last shot on list is the current active shot,
					//so follow it
					b2Vec2 pos = shotEntityList[size - 1]->body->GetPosition();
					pos = Physics2Pixels(pos);
					camera->PanTo(pos.x, pos.y);
				}				
			}
			camera->Update(timeStep);

			//update the particle list and remove dead particles
			for (int i = particleList.size() - 1; i >= 0; --i)
			{
				if (particleList[i]->Update(timeStep))
				{
					//time to die!
					delete particleList[i];
					particleList.erase(particleList.begin() + i);
				}
			}

			//loop over contacts
			for (int pos = 0; pos < contactListener->contacts.size(); ++pos)
			{
				MyContact contact = contactListener->contacts[pos];

				//fetch the entities from the body userdata
				Entity *A = (Entity *)contact.fixtureA->GetBody()->GetUserData().pointer;
				Entity *B = (Entity *)contact.fixtureB->GetBody()->GetUserData().pointer;

				if (A != NULL && B != NULL) //if there is an entity for these objects...
				{
					if (A->typeID == EntityTypes::ENTITYBLOCK)
					{
						BlockCollide(A, contact.maxImpulseAB);
					}

					if (B->typeID == EntityTypes::ENTITYBLOCK)
					{
						BlockCollide(B, contact.maxImpulseAB);
					}
					if (A->typeID == EntityTypes::ENTITYALIEN)
					{
						AllienCollide(A, contact.maxImpulseAB);
					}

					if (B->typeID == EntityTypes::ENTITYALIEN)
					{
						AllienCollide(B, contact.maxImpulseAB);
					}
				}
			}

			//clean up dead entities
			for (auto &e : deadEntityList)
			{
				//remove body from the physics world and free the body data
				world->DestroyBody(e->body);
				//remove the entity from the appropriate entityList
				if (e->typeID == ENTITYSHOT)
				{
					for (int i = 0; i < shotEntityList.size(); ++i)
					{
						if (e == shotEntityList[i])
						{
							delete shotEntityList[i];
							shotEntityList.erase(shotEntityList.begin() + i);
							break;
						}
					}
				}
				else if (e->typeID == ENTITYBLOCK)
				{
					for (int i = 0; i < blockEntityList.size(); ++i)
					{
						if (e == blockEntityList[i])
						{
							//points = points + blockEntityList[i].
							delete blockEntityList[i];
							blockEntityList.erase(blockEntityList.begin() + i);
							break;
						}
					}
				}
				else if (e->typeID == ENTITYALIEN)
				{
					for (int i = 0; i < alienEntityList.size(); ++i)
					{
						if (e == alienEntityList[i])
						{
							delete alienEntityList[i];
							alienEntityList.erase(alienEntityList.begin() + i);
							break;
						}
					}
				}
				else
				{
					for (int i = 0; i < entityList.size(); ++i)
					{
						if (e == entityList[i])
						{
							delete entityList[i];
							entityList.erase(entityList.begin() + i);
							break;
						}
					}
				}
			}

			deadEntityList.clear();
		}
	}
	if (alienEntityList.size() == 0)
	{
		//world->ClearForces();
		//generateLevel();// gameState = GameState::GAMEOVER;//here?
		gameState = GameState::GAMEOVER;
	}
	if (lives == 0) gameState = GameState::GAMEOVER;//here?
	break;

	case START:
	case GAMEOVER:
		camera->StopShaking();

		break;

	default:
		//do nada here
		break;
	}//end switch(gameState)
}

void Draw(void)
{
	glClearColor(0.5f, 0.5f, 1.0f, 0.0f);	//clear colour: r,g,b,a 	
											// wipe the drawing surface clear
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//draw stuff here
	switch (gameState)
	{
	case START:
		camera->UnDraw();
		logo->Blit(blit3D->screenWidth / 2, blit3D->screenHeight / 2);
		break;

	case SETTLING:
		caviar57font->BlitText(blit3D->screenWidth/2, blit3D->screenHeight/2, "READY?");
	case PLAYING:
	{//MUST draw camera first!
		camera->Draw();

		//throw in a few graphical things, clouds and cactii
		for (auto& e : elementList) e->Draw();

		//loop over all entities and draw them
		for (auto& e : entityList) e->Draw();
		for (auto& b : blockEntityList) b->Draw();
		for (auto& a : alienEntityList) a->Draw();
		for (auto& b : shotEntityList) b->Draw();
		for (auto& p : particleList) p->Draw();
		cannon.Draw();
		meter.Draw();
		std::string text = "Points: " + std::to_string(points);
		caviar57font->BlitText(50, blit3D->screenHeight-50, text);
		text = "Aliens on play: " + std::to_string(alienEntityList.size());
		caviar57font->BlitText(50, blit3D->screenHeight - 100, text);
		text = "Shots remaining: " + std::to_string(lives);
		caviar57font->BlitText(50, blit3D->screenHeight - 150, text);
	}
	break;
	case GAMEOVER:
	{	camera->UnDraw();
		logoGO->Blit(blit3D->screenWidth / 2, blit3D->screenHeight / 2);
		std::string text = "MaxScore: " + std::to_string(points);
		caviar57font->BlitText(50, blit3D->screenHeight - 100, text);
	}
		break;
	}
}

//the key codes/actions/mods for DoInput are from GLFW: check its documentation for their values
void DoInput(int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		blit3D->Quit(); //start the shutdown sequence
	switch(gameState) {
	case GameState::START:
		if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
			gameState=GameState::SETTLING;
		break;
	case GameState::SETTLING:
	case GameState::PLAYING:
	{


		if (key == GLFW_KEY_D && (action == GLFW_PRESS || action == GLFW_REPEAT))
			cannon.rotateDir = -1.f;

		if (key == GLFW_KEY_A && (action == GLFW_PRESS || action == GLFW_REPEAT))
			cannon.rotateDir = 1.f;

		if ((key == GLFW_KEY_A || key == GLFW_KEY_D) && action == GLFW_RELEASE)
			cannon.rotateDir = 0;

		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			meter.shooting = true;
			//camera->PanTo(0,0);
		}

		if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
		{
			meter.shooting = false;
			fireShotNow = true;
		}

		if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			camera->Pan(1, 0);
			followingShot = false;
		}

		if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			camera->Pan(-1, 0);
			followingShot = false;
		}

		if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_RIGHT) && action == GLFW_RELEASE)
			camera->Pan(0, 0);

		if (key == GLFW_KEY_UP && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			camera->Pan(0, 1);
			followingShot = false;
		}

		if (key == GLFW_KEY_DOWN && (action == GLFW_PRESS || action == GLFW_REPEAT))
		{
			camera->Pan(0, -1);
			followingShot = false;
		}

		if ((key == GLFW_KEY_DOWN || key == GLFW_KEY_UP) && action == GLFW_RELEASE)
			camera->Pan(0, 0);
	}
	break;
	case GameState::GAMEOVER:
		if (key == GLFW_KEY_SPACE && action == GLFW_RELEASE)
			gameState = GameState::START;
		break;
	default:
		break;
	}
	
	
}

int main(int argc, char *argv[])
{
	//memory leak detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	blit3D = new Blit3D(Blit3DWindowModel::BORDERLESSFULLSCREEN_1080P, 720, 480);

	//set our callback funcs
	blit3D->SetInit(Init);
	blit3D->SetDeInit(DeInit);
	blit3D->SetUpdate(Update);
	blit3D->SetDraw(Draw);
	blit3D->SetDoInput(DoInput);

	//Run() blocks until the window is closed
	blit3D->Run(Blit3DThreadModel::SINGLETHREADED);
	if (blit3D) delete blit3D;
}