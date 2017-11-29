#pragma once

struct Point
{
	double x, y, z;
};

class vector3
{
public://todo make generic type
	vector3();
	static double Normal(const double* vec3);
	static void Normalize(const double* vec3, double* resultVecf);
	static void Subtract(const double* firstVec3, const double* secondVec3, double* resultVec3);
	static void Cross(const double* firstVec3, const  double* secondVec3, double* resultVecf);
	static double Dot(const double* firstVec3, const  double* secondVec3);
	~vector3();
};

