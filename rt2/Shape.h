#pragma once

class Ray3;
#include "vector3.h"
#include <math.h>

class Shape
{
protected:
	unsigned char color[4];
	virtual  ~Shape() {}//todo figure out destructors

public:
	virtual bool LineIntersect(Ray3* ray) = 0;
	virtual bool ShadowAtIntersection(Ray3* ray) = 0;
	unsigned char* GetColor() { return color; };
};
