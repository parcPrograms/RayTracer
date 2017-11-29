#include "stdafx.h"
#include "Camera.h"
#include "Ray3.h"
#include "vector3.h"
#include <iostream>
using namespace std;



Camera::Camera(unsigned char * d, const int * h, const int * w, const int * c, const double * pos, const double * lookpos, const double * upVec, const double* depth, Shape** objList, int objListSize)
{
	data = d;
	height = h;
	width = w;
	channels = c;
	position = pos;
	lookAt = lookpos;
	up = upVec;
	fov = depth;
	objectList = objList;
	objectListSize = objListSize;
	
	//https://www.unc.edu/courses/2005spring/comp/236/001/Lecture17.pdf
	double look[3] = { *lookAt - *position, *(lookAt+1) - *(position + 1), *(lookAt + 2) - *(position + 2) };
	vector3::Cross(look, up, Du);
	vector3::Normalize(Du, Du);
	vector3::Cross(look, Du, Dv);
	vector3::Normalize(Dv, Dv);
	double dl = *width / (2 *tan((0.5**fov)*3.1415926535897 / 180));
	vector3::Normalize(&look[0], Vp);
	Vp[0] = Vp[0]*dl - 0.5*(*width*Du[0] + *height*Dv[0]);
	Vp[1] = Vp[1]*dl - 0.5*(*width*Du[1] + *height*Dv[1]);
	Vp[2] = Vp[2]*dl - 0.5*(*width*Du[2] + *height*Dv[2]);
	//vector3::Normalize(Vp, Vp);
	cout << "Camera online" << endl;
}

Camera::~Camera()
{
	cout << "Camera offline" << endl;
}

void Camera::Run()
{
	cout << "Camera starting"<< endl;
	int memCounter = ((*height**width)-1)* (*channels);
	for (int i = (*height)-1; i >= 0; --i) {
		for (int j = (*width)-1; j >= 0; --j)
		{
			this->RenderPixel(i, j, memCounter);
			memCounter-= *channels;
		}
	}
	cout << "Camera finished" << endl;
}

void Camera::RenderPixel(double y, double x, int memPos)
{
	Ray3 r(*position, *(position + 1),*(position+2), x * Du[0] + y * Dv[0] + Vp[0], x * Du[1] + y * Dv[1] + Vp[1], x * Du[2] + y * Dv[2] + Vp[2], 0, objectList, objectListSize);
	unsigned char* colors = r.RunForColor();
	for (int i = 0; i < *channels; ++i) {
		*(data + memPos + i) = *(colors + i);
	}
}
