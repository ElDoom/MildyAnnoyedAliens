#pragma once
#include "Blit3D.h"
#include <iostream>
extern Blit3D* blit3D;
extern std::vector<Sprite*> blockElementList;

class GraphicElement
{
public:
	Sprite* sprite;
	glm::vec2 pos;
	float angleInDegrees=0.f;
	void Draw()
	{
		sprite->angle = angleInDegrees;
		sprite->Blit(pos.x, pos.y);
	};
	
};

void LoadGraphicElements(std::string fileName, std::vector<Sprite*> vectorList, std::vector<GraphicElement*> &elementList) {
	std::string nonPhisicsName = fileName;
	//clear the current elementList
	for (auto B : elementList) delete B;
	elementList.clear();

	//open files
	std::ifstream myfileNP;

	myfileNP.open(fileName);
	//assert(!myfileNP.open(fileName));

	if (myfileNP.is_open())
	{
		//read in # of Elements
		int elementNum = 0;
		myfileNP >> elementNum;
		
		//read in each element
		for (; elementNum > 0; --elementNum)
		{
			//make an Element*
			GraphicElement* B = new GraphicElement();
			int totalOffset = 0, offsetA=0, offsetB=0, x=0, y=0, angle=0;
			myfileNP >> offsetA;
			myfileNP >> offsetB;
			myfileNP >> x;
			myfileNP >> y;
			myfileNP >> angle;
			totalOffset = offsetA + (offsetB * 10);
			//std::cout << "Sprite number " << totalOffset << std::endl;
			B->sprite = vectorList[totalOffset];
			B->pos= glm::vec2(x, y);
			B->angleInDegrees = angle;
			elementList.push_back(B);
			
		}

		myfileNP.close();
	}
	else assert(false);
};


void LoadGraphicElements(std::string fileName, std::vector<GraphicElement*>& elementList) {
	std::string nonPhisicsName = fileName;
	//clear the current elementList
	for (auto B : elementList) delete B;
	elementList.clear();

	//open files
	std::ifstream myfileNP;

	myfileNP.open(fileName);
	//assert(!myfileNP.open(fileName));

	if (myfileNP.is_open())
	{
		//read in # of Elements
		int elementNum = 0;
		myfileNP >> elementNum;

		//read in each element
		for (; elementNum > 0; --elementNum)
		{
			//make an Element*
			GraphicElement* B = new GraphicElement();
			int totalOffset = 0, offsetA = 0, offsetB = 0, x = 0, y = 0, angle = 0;
			myfileNP >> offsetA;
			myfileNP >> offsetB;
			myfileNP >> x;
			myfileNP >> y;
			myfileNP >> angle;
			totalOffset = offsetA + (offsetB * 10);
			B->sprite = blockElementList[totalOffset];
			B->pos = glm::vec2(x, y);
			B->angleInDegrees = angle;
			elementList.push_back(B);

		}

		myfileNP.close();
	}
	else assert(false);
};
