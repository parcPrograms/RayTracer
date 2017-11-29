#include "stdafx.h"
#include "RayPool.h"
#include "Ray3.h"
#include <iostream>
using namespace std;

RayPool* RayPool::instance = nullptr;

RayPool::RayPool()
{
	cout << "RayPool online" << endl;
}


RayPool::~RayPool()
{
	//TODO instance null? free up list?
	cout << "RayPool offlne" << endl;
}

RayPool * RayPool::GetInstance()
{
	if (instance == nullptr)
	{
		instance = new RayPool();
		
	}
	return instance;
}

void * RayPool::GetNewRay()
{
	//todo ray cap?
	if (unusedRays.ray == nullptr) {
		//unusedRays.ray = new Ray3();
	}
	//cout << *(((Ray3*)unusedRays.ray)->run());
	void* ray = unusedRays.ray;
	//cout << *(((Ray3*)ray)->Run());
	if (unusedRays.next == nullptr) {
		unusedRays.ray = nullptr;
	}
	else {
		unusedRays = *unusedRays.next;
	}

	return ray;
}

void RayPool::ReturnRay(void * ray)
{
	//TODO make sure it was a passed out ray?
	if (unusedRays.ray == nullptr) {
		unusedRays.ray = ray;
	}
	else {
		LinkedRay* iterate = &unusedRays;
		while (iterate->next != nullptr)
		{
			iterate = iterate->next;
		}
		iterate->next = new LinkedRay();
		iterate->next->ray = ray;
	}
}
