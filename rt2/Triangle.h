#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
private:

	double edge1[3];
	double edge2[3];
	Point* pt1;
	Point* pt2;
	Point* pt3;
	
	
public:
	bool set = false;
	Triangle();
	void Set(unsigned char r, unsigned char g, unsigned char b, unsigned char a, Point* p1, Point* p2, Point* p3);
	Triangle(unsigned char r, unsigned char g, unsigned char b, unsigned char a, Point* p1, Point* p2, Point* p3);
	~Triangle();
	bool LineIntersect(Ray3* ray) override;
	bool ShadowAtIntersection(Ray3* ray) override;

};

