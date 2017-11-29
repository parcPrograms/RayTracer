#pragma once

#include "Shape.h"
#include "Triangle.h"
#include <iostream>


class Ray3
{
private:
	//default color
	Shape** objectList = nullptr;
	int objectListSize;

public:
	unsigned char colors[3] = { 100,149,237 };

	double origin[3];
	double direction[3];
	int depthCount;
	double t = DBL_MAX;
	Shape* object = nullptr;

	Ray3(double posX, double posY, double posZ, double dirI, double dirJ, double dirK, int depthNum, Shape** objList, int objListSize);
	~Ray3();
	unsigned char* RunForColor();
	unsigned char* AddShadowToColor();
};