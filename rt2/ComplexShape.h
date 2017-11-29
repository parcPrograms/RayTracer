#pragma once
#include "Shape.h"
#include "BoundingShape.h"
#include "vector3.h"
#include "Triangle.h"

class ComplexShape :
	public Shape
{
private:
	double position[3];//todo this?
	Triangle* shapes;
	Point* pts;
	int ptsSize = 0;
	Point* tris;
	int trisSize = 0;
	BoundingShape* bound;
	unsigned char color[4];

public:
	bool LineIntersect(Ray3* ray) override;
	bool ShadowAtIntersection(Ray3* ray) override;
	ComplexShape(unsigned char r, unsigned char g, unsigned char b, unsigned char a, Point* points, int pointsSize, Point* triangles, int trianglesSize);
	~ComplexShape();
};

