#pragma once

#include "Shape.h"
#include "Triangle.h"

class Camera
{
private:
	unsigned char* data;//pointer to data array [height][width][channels]
	const int* height;
	const int* width;
	const int* channels;
	const double* position;// pointer to array [3] (xyz)
	const double* lookAt;// pointer to array [3] (xyz)
	const double* up;// pointer to array [3] (ijk)
	double Du[3];
	double Dv[3];
	double Vp[3];
	const double* fov;
	Shape** objectList;
	int objectListSize;

	void RenderPixel(double i, double j, int memPos);
public:
	Camera(unsigned char* d, const int* h, const int* w, const int* c, const double* pos, const double* look, const double* up, const double* depth, Shape** objList, int objListSize);
	~Camera();
	void Run();
};

