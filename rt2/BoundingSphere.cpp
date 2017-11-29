#include "stdafx.h"
#include "BoundingSphere.h"
#include "Ray3.h"   
#include <algorithm> 
#include <iostream>

using namespace std;


BoundingSphere::BoundingSphere(Point* coOrd, int coOrdSize)
{//todo make this a minimum bounding sphere eventually
	if (coOrdSize < 3) {
		cout << "not enoug points to make bounding sphere" << endl;
		return;
	}

	double xMax, xMin, yMax, yMin, zMax, zMin;
	xMax = xMin = (*(coOrd + (coOrdSize - 1))).x;
	yMax = yMin = (*(coOrd + (coOrdSize - 1))).y;
	zMax = zMin = (*(coOrd + (coOrdSize - 1))).z;
	cout << xMax << " " << yMax << " " << zMax << endl;

	for (int i = coOrdSize-2; i >= 0; --i) {
		zMax = max(zMax, (*(coOrd + i)).z);
		zMin = min(zMin, (*(coOrd + i)).z);
		yMax = max(yMax, (*(coOrd + i)).y);
		yMin = min(yMin, (*(coOrd + i)).y);
		xMax = max(xMax, (*(coOrd + i)).x);
		xMin = min(xMin, (*(coOrd + i)).x);
	}

	cout << xMax << " " << yMax << " " << zMax << endl;
	cout << xMin << " " << yMin << " " << zMin << endl;

	position[0] = (xMax - (xMax - xMin)*0.5);
	position[1] = (yMax - (yMax - yMin)*0.5);
	position[2] = (zMax - (zMax - zMin)*0.5);
	cout << position[0] << " " << position[1] << " " << position[2] << endl;

	radius = std::sqrt(
		abs((position[0] - xMax)*(position[0] - xMax)) + 
		abs((position[1] - yMax)*(position[1] - yMax)) + 
		abs((position[2] - zMax)*(position[2] - zMax)));
	radSqrd = radius*radius;
}

bool BoundingSphere::LineIntersect(Ray3 * ray)
{
	double delta[3] = { (position[0] - ray->origin[0]), position[1] - (ray->origin[1]), position[2] - ray->origin[2] };

	double v = vector3::Dot(ray->direction, delta);

	//todo test if behind ray origin and/or outside view box
	//test if line is before/after front/back of shpere
	if (v - radius > ray->t || v + radius < 0)
		return false;

	// Test if the ray intersects  sphere
	double t = radSqrd + v*v - vector3::Dot(delta, delta);
	if (t < 0)
		return false;

	//check if the intersection point is the new closest
	t = (sqrt(t));
	t = fmin(v + t, v - t);
	if ((t > ray->t) || (t < 0))
		return false;

	return true;
}


BoundingSphere::~BoundingSphere()
{
}
