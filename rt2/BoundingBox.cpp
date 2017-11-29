#include "stdafx.h"
#include "BoundingBox.h"
#include <algorithm>
#include <iostream>

using namespace std;


BoundingBox::BoundingBox(Point* coOrd, int coOrdSize)
{//todo make this a minimum bounding box
	if (coOrdSize < 3) {
		cout << "not enoug points to make bounding box" << endl;
		return;
	}

	ptMax[0] = ptMin[0] = (*(coOrd + (coOrdSize - 1))).x;
	ptMax[1] = ptMin[1] = (*(coOrd + (coOrdSize - 1))).y;
	ptMax[2] = ptMin[2] = (*(coOrd + (coOrdSize - 1))).z;

	for (int i = coOrdSize - 2; i >= 0; --i) {
		ptMax[2] = max(ptMax[2], (*(coOrd + i)).z);
		ptMin[2] = min(ptMin[2], (*(coOrd + i)).z);
		--i;
		ptMax[1] = max(ptMax[1], (*(coOrd + i)).y);
		ptMin[1] = min(ptMin[1], (*(coOrd + i)).y);
		--i;
		ptMax[0] = max(ptMax[0], (*(coOrd + i)).x);
		ptMin[0] = min(ptMin[0], (*(coOrd + i)).x);
	}
}

bool BoundingBox::LineIntersect(Ray3 * ray)
{
	//todo this...
	return true;
}


BoundingBox::~BoundingBox()
{
}
