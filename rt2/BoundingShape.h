#pragma once

class Ray3;
#include "vector3.h"
#include <math.h>

class BoundingShape
{
public:
	virtual bool LineIntersect(Ray3* ray) = 0;
	~BoundingShape() {};
};

