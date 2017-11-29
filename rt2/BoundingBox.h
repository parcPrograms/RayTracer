#pragma once
#include "BoundingShape.h"
class BoundingBox :
	public BoundingShape
{
private:
	double ptMax[3];
	double ptMin[3];
public:
	BoundingBox(Point* coOrd, int coOrdSize);
	bool LineIntersect(Ray3* ray) override;
	~BoundingBox();
};

