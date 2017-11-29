#pragma once
#include "BoundingShape.h"
class BoundingSphere :
	public BoundingShape
{
private:
	double position[3];
	double radius;
	double radSqrd;
public:
	BoundingSphere(Point* coOrd, int coOrdSize);//todo set points and radius automatically off of shape indexs
	bool LineIntersect(Ray3* ray) override;
	~BoundingSphere();
};

