#include "stdafx.h"
#include "Triangle.h"
#include "Ray3.h"
#include <iostream>


using namespace std;


Triangle::Triangle()
{
}

void Triangle::Set(unsigned char r, unsigned char g, unsigned char b, unsigned char a, Point* p1, Point* p2, Point* p3)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
	pt1 = p1;
	pt2 = p2;
	pt3 = p3;
	double d1[3] = { pt1->x, pt1->y, pt1->z };
	double d2[3] = { pt2->x, pt2->y, pt2->z };
	double d3[3] = { pt3->x, pt3->y, pt3->z };
	vector3::Subtract(d2, d1, edge1);
	vector3::Subtract(d3, d1, edge2);
	set = true;
}

Triangle::Triangle(unsigned char r, unsigned char g, unsigned char b, unsigned char a, Point* p1, Point* p2, Point* p3)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
	color[3] = a;
	pt1 = p1;
	pt2 = p2;
	pt3 = p3;
	double d1[3] = { pt1->x, pt1->y, pt1->z };
	double d2[3] = { pt2->x, pt2->y, pt2->z };
	double d3[3] = { pt3->x, pt3->y, pt3->z };
	vector3::Subtract(d2, d1, edge1);
	vector3::Subtract(d3, d1, edge2);
	set = true;
}


Triangle::~Triangle()
{
}

bool Triangle::LineIntersect(Ray3 * ray)
{
	if (!set) {
		cout << "triangle not set cant test intersection" << endl;
	}
		double tvec[3], pvec[3], qvec[3];
		double det, inv_det, u, v;

		/* begin calculating determinant - also used to calculate U parameter */
		vector3::Cross(ray->direction, edge2, pvec);

		/* if determinant is near zero, ray lies in plane of triangle */
		det = vector3::Dot(edge1, pvec);

		if (det > -0.000001 && det < 0.000001) {//((unsigned int)((det+0.000001d)*1000000)<2) ?
			//ray->colors[2] = ray->colors[2] + 60;
			return false;
		}
		inv_det = 1.0 / det;

		/* calculate distance from vert0 to ray origin */
		double d1[3] = { pt1->x, pt1->y, pt1->z };
		vector3::Subtract(ray->origin, d1, tvec);
		
		/* calculate U parameter and test bounds */
		u = vector3::Dot(tvec, pvec) * inv_det;
		if (u < 0.0 || u > 1.0) {//(((unsigned int)u) > 1){// ?
			//ray->colors[2] = ray->colors[2] + 120;
			return false;
		}
		/* prepare to test V parameter */
		vector3::Cross(tvec, edge1, qvec);

		/* calculate V parameter and test bounds */
		v = vector3::Dot(ray->direction, qvec) * inv_det;
		if (v < 0.0 || u + v > 1.0) {
			//ray->colors[2] = ray->colors[2] + 180;
			return false;
		}


		/* calculate t, ray intersects triangle */
		double t = vector3::Dot(edge2, qvec) * inv_det;
		//cout << t << endl;
		if (t > ray->t || t < 0) {
			//cout << "red t " << t << " < " << ray->t << " green" << endl;
			//ray->colors[2] = ray->colors[2] + 240;
			return false;
		}
		else if (ray->t < DBL_MAX) {
			//cout << "red t " << t << " > " << ray->t << " green" << endl;
		}
		ray->t=t;
		ray->object = this;

		return true;

}

bool Triangle::ShadowAtIntersection(Ray3 * ray)
{
	return false;
}
