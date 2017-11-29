// rt2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Camera.h"
#include "Shape.h"
#include "Sphere.h"
#include "Triangle.h"
#include "ComplexShape.h"
#include "vector3.h"
#include <iostream>
using namespace std;

int main()
{
	const char *FILENAME = "n.ppm";
	const int WIDTH = 1600;
	const int HEIGHT = 1600;
	const int MAXCOLOR = 255;
	const int CHANNELS = 3; //1 for grey scale, 3 rgb, 4 rgba //TODO later
	const double CAMERAPOS[3] = { 0,1,-11 };//camera position (xyz)
	const double CAMERALOOK[3] = { 0,0,0 };//camera position to look at (xyz)
	const double CAMERAUP[3] = { 0,1,0 };//camera up dirction (ijk)
	const double MAXCAMERADEPTH = 30;

	unsigned char* data = new unsigned char[HEIGHT*WIDTH*CHANNELS];// [HEIGHT][WIDTH][CHANNELS];//TODO this breaks when height*width*channels > max of int
	
	cout << "starting"<<endl;
	
	/*
	double t1p1[3] = { 0,0,2 };
	double t1p2[3] = { 1,1,2 };
	double t1p3[3] = { -1,3,2 };

	double t2p1[3] = { 0,0,7 };
	double t2p2[3] = { -1,-1,7 };
	double t2p3[3] = { 5,-4,7 };

	double t3p1[3] = { 1,2,2 };
	double t3p2[3] = { -1,-1,2 };
	double t3p3[3] = { 2,-2,2 };
	//Shape* objects[6] = { new Triangle(255,0,255,1,t1p1,t1p2,t1p3), new Sphere(255,0,0,1,-2,0,5,2), new Sphere(0,255,0,1,0,0,6,2),new Triangle(0,255,255,1,t3p1,t3p2,t3p3), new Sphere(0,0,255,1,0,2,5,2), new Triangle(255,255,0,1,t2p1,t2p2,t2p3) };
	Shape* objects[3] = { new Triangle(255,0,0,1,t1p1,t1p2,t1p3), new Triangle(0,0,255,1,t3p1,t1p2,t3p3), new Triangle(0,255,0,1,t3p1,t3p2,t3p3)};
	*/

	//todo make this set a single complex object
	Point t1p1 = { 0,-2.2,7 };
	Point t1p2 = { 0,-1,7 };
	Point t1p3 = { 1.2,-2,8 };
	Point t1p4 = { 1.6,-0.8,8 };
	Point t1p5 = { 2,-1.6,9 };
	Point t1p6 = { 2.6,-0.6,10 };
	Point t1p7 = { -1.2,-2,8 };
	Point t1p8 = { -1.6,-0.8,8 };
	Point t1p9 = { -2,-1.6,9 };
	Point t1p10 = { -2.6,-0.6,10 };

	Point t2p1 = { 1,2,3 };
	Point t2p2 = { 2,3,4 };
	Point t2p3 = {3,4,5};
	Point t2p4 = { 4,5,6 };
	Point t2p5 = { 1,2,7 };
	Point t2p6 = { 2,7,8 };
	Point t2p7 = { 7,8,9 };
	Point t2p8 = { 8,9,10 };

	Point pts[10] = { t1p1 ,t1p2 ,t1p3 ,t1p4 ,t1p5 ,t1p6 ,t1p7 ,t1p8 ,t1p9 ,t1p10 };
	Point tris[8] = { t2p1 ,t2p2 ,t2p3 ,t2p4 ,t2p5 ,t2p6 ,t2p7 ,t2p8  };

	ComplexShape* c = new ComplexShape(0, 0, 0, 1, pts, 10, tris, 8);

	//Shape* objects[11] = { new Sphere(255,255,0,1,0,-1.5,19,4),new Sphere(0,0,0,1,1.3,0.3,12,0.8),new Sphere(0,0,0,1,-1.3,0.3,12,0.8),new Triangle(0,0,0,1,&t1p1,&t1p2,&t1p3),new Triangle(0,0,0,1,&t1p3,&t1p2,&t1p4),new Triangle(0,0,0,1,&t1p3,&t1p4,&t1p5),new Triangle(0,0,0,1,&t1p6,&t1p5,&t1p4),new Triangle(0,0,0,1,&t1p1,&t1p2,&t1p7),new Triangle(0,0,0,1,&t1p8,&t1p2,&t1p7),new Triangle(0,0,0,1,&t1p7,&t1p8,&t1p9),new Triangle(0,0,0,1,&t1p8,&t1p9,&t1p10) };
	Shape* objects[4] = { new Sphere(255,255,0,1,0,-1.5,29,4),new Sphere(0,0,0,1,1.3,0.3,12,0.8),new Sphere(0,0,0,1,-1.3,0.3,12,0.8), c };

	Camera camera(data, &HEIGHT, &WIDTH, &CHANNELS, &CAMERAPOS[0], &CAMERALOOK[0], &CAMERAUP[0], &MAXCAMERADEPTH, &objects[0], 4);
	camera.Run();

	cout << "printing"<<endl;
	FILE * fp;
	fp = fopen(FILENAME, "wb");
	fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAXCOLOR);
	fwrite(data, sizeof(char)*HEIGHT*WIDTH*CHANNELS, 1, fp);
	fclose(fp);
	
	delete[] data;

    return 0;
}

