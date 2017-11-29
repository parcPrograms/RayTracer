#pragma once

#include "Shape.h"

class Sphere : public Shape
{
private:
	double position[3];
	double radius;
	double radSqrd;
public:
	Sphere(unsigned char r, unsigned char g, unsigned char b, unsigned char a, double posX, double posY, double posZ, double rad);
	~Sphere();
	bool LineIntersect(Ray3* ray) override;
	bool ShadowAtIntersection(Ray3* ray) override;
};

