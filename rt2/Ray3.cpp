#include "stdafx.h"
#include "Ray3.h"
#include "vector3.h"
#include "Triangle.h"
#include <iostream>
using namespace std;


Ray3::Ray3(double posX, double posY, double posZ, double dirI, double dirJ, double dirK, int depthNum, Shape** objList, int objListSize)
{
	origin[0] = posX;
	origin[1] = posY;
	origin[2] = posZ;
	direction[0] = dirI;
	direction[1] = dirJ;
	direction[2] = dirK;
	vector3::Normalize(direction, direction);
	depthCount = depthNum;
	objectList = objList;
	objectListSize = objListSize;
}


Ray3::~Ray3()
{
}

unsigned char * Ray3::RunForColor()
{
	if (objectList == nullptr)
		return colors;

	for (int i = objectListSize - 1; i >= 0; --i) {
		(*(objectList+i))->LineIntersect(this);
	}

	if (object != nullptr) {
		unsigned char* temp = object->GetColor();
		colors[0] = *temp; //colors[0]+*temp;
		colors[1] = *(temp + 1);// colors[1] + (*(temp + 1));
		colors[2] = *(temp + 2);// colors[2] + (*(temp + 2));
	}
	
	return colors;
}

unsigned char * Ray3::AddShadowToColor()
{
	if (object != nullptr)
		object->ShadowAtIntersection(this);

	return colors;
}
