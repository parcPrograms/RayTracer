#include "stdafx.h"
#include "vector3.h"
#include <math.h>
#include <iostream>
using namespace std;


vector3::vector3()
{
}

double vector3::Normal(const double * vec3)
{
	return sqrt((*vec3**vec3)+(*(vec3+1)**(vec3+1))+(*(vec3+2)**(vec3+2)));
}

void vector3::Normalize(const double * vec3, double * resultVec3)
{
	double normal = Normal(vec3);
	*resultVec3 = *vec3 / normal;
	*(resultVec3+1) = *(vec3 +1) / normal;
	*(resultVec3+2) = *(vec3 +2) / normal;
}

void vector3::Subtract(const double * firstVec3, const  double * secondVec3, double * resultVec3)
{
	*resultVec3 = (*firstVec3) - (*secondVec3);
	*(resultVec3 + 1) = (*(firstVec3 + 1)) - (*(secondVec3 + 1));
	*(resultVec3 + 2) = (*(firstVec3+2)) - (*(secondVec3+2));
}

void vector3::Cross(const double * firstVec3, const  double * secondVec3, double * resultVec3)
{
	*resultVec3 = *(firstVec3+1)**(secondVec3+2) - *(firstVec3+2)**(secondVec3+1);
	*(resultVec3+1) = *(firstVec3+2)**secondVec3 - *firstVec3**(secondVec3+2);
	*(resultVec3+2) = *firstVec3**(secondVec3+1) - *(firstVec3+1)**secondVec3;
}

double vector3::Dot(const double * firstVec3, const  double * secondVec3)
{
	return (*firstVec3**secondVec3) + (*(firstVec3+1)**(secondVec3+1)) + (*(firstVec3+2)**(secondVec3+2));
}


vector3::~vector3()
{
}
