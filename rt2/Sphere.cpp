#include "stdafx.h"
#include "Sphere.h"
#include "Ray3.h"
#include <iostream>
using namespace std;

Sphere::Sphere(unsigned char r, unsigned char g, unsigned char b, unsigned char a, double posX, double posY, double posZ, double rad)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
	position[0] = posX;
	position[1] = posY;
	position[2] = posZ;
	radius = rad;
	radSqrd = rad*rad;
}


Sphere::~Sphere()
{
}

bool Sphere::LineIntersect(Ray3 * ray)
{
	double delta[3] = { (position[0] - ray->origin[0]), position[1] - (ray->origin[1]), position[2] - ray->origin[2] };

	double v = vector3::Dot(ray->direction, delta);

	//todo test if behind ray origin and/or outside view box
	//test if line is before/after front/back of shpere
	if (v - radius > ray->t || v + radius < 0)
		return false;

	// Test if the ray intersects  sphere
	double t = radSqrd + v*v - vector3::Dot(delta,delta);
	if (t < 0)
		return false;

	//check if the intersection point is the new closest
	t = (sqrt(t));
	t = fmin(v + t, v - t);
	if ((t > ray->t) || (t < 0))
		return false;
	
	//set as new closest
	ray->t = t;
	ray->object = this;
	return true;
}

bool Sphere::ShadowAtIntersection(Ray3 * ray)
{
	return false;
}
