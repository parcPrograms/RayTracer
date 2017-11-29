#include "stdafx.h"
#include "ComplexShape.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"
#include "Ray3.h"
#include <iostream>

using namespace std;


bool ComplexShape::LineIntersect(Ray3 * ray)
{
	if (!bound->LineIntersect(ray)) {
		//ray->colors[1] = 255;
		return false;
	}

	bool temp = false;

	for (int i = trisSize - 1; i >= 0; --i) {
		temp = (shapes[i]).LineIntersect(ray);
	}

	return temp;
}

bool ComplexShape::ShadowAtIntersection(Ray3 * ray)
{
	//todo this...
	return false;
}

ComplexShape::ComplexShape(unsigned char r, unsigned char g, unsigned char b, unsigned char a, Point* points, int pointsSize, Point* triangles, int trianglesSize)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;

	pts = points;
	ptsSize = pointsSize;
	tris = triangles;
	trisSize = trianglesSize;

	//todo fill shapes with triangles

	shapes = new Triangle[trianglesSize];
	//if ((dynamic_cast<Triangle*>(&shapes[7])) == nullptr) {
		//cout << "null" << endl;
	//}
	//cout<<((dynamic_cast<Triangle*>(shapes))[0]).set << endl;
	//cout << ((dynamic_cast<Triangle*>(shapes))[1]).set << endl;
	//(dynamic_cast<Triangle*>(&shapes[7]))->Set(r, g, b, a, (pts + static_cast<int>(((tris + 7)->x) - 1)), (pts + static_cast<int>(((tris + 7)->y) - 1)), (pts + static_cast<int>(((tris + 7)->z) - 1)));
	//cout << (dynamic_cast<Triangle*>(&shapes[7]))->set << endl;
	//r = 255;
	for (int i = trianglesSize - 1; i >= 0; --i) {
		/*
				((dynamic_cast<Triangle*>(shapes))[i]).Set(r,g,b,a, (pts + static_cast<int>(((tris + i)->x)-1)), (pts + static_cast<int>(((tris + i)->y)-1)), (pts + static_cast<int>(((tris + i)->z)-1)));
		cout << (i) << endl;
		cout << (tris + (i))->x << endl;
		cout << (((tris + (i))->x) - 1) << endl;
		cout << static_cast<int>(((tris + (i))->x) - 1) << endl;
		cout << (pts + static_cast<int>(((tris + (i))->x)) - 1)->x << endl;
		cout << (tris + (i))->y << endl;
		cout << (((tris + (i))->y) - 1) << endl;
		cout << static_cast<int>(((tris + (i))->y) - 1) << endl;
		cout << (pts + static_cast<int>(((tris + (i))->y)) - 1)->x << endl;
		cout << (tris + (i))->z << endl;
		cout << (((tris + (i))->z) - 1) << endl;
		cout << static_cast<int>(((tris + (i))->z) - 1) << endl;
		cout << (pts + static_cast<int>(((tris + (i))->z)) - 1)->x << endl;*/
		(shapes[i]).Set(r,g,b,a, (pts + static_cast<int>(((tris + i)->x)-1)), (pts + static_cast<int>(((tris + i)->y)-1)), (pts + static_cast<int>(((tris + i)->z)-1)));
		//r +=30;
	}

	bool boundingShapeTSFB = true;//todo remove when box is ready
	if (boundingShapeTSFB) {//todo this...
		bound = new BoundingSphere(points, pointsSize);
	}
	else {
		//bound = new BoundingBox();
	}
}


ComplexShape::~ComplexShape()
{
}
