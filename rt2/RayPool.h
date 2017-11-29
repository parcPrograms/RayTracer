#pragma once

//todo use later?
struct LinkedRay
{
	void* ray = nullptr;
	LinkedRay* next = nullptr;
};

class RayPool
{
private:
	static RayPool* instance;
	const int* channels;
	LinkedRay unusedRays;//todo alloc/pointer?
	RayPool();
public:
	~RayPool();
	static RayPool* GetInstance();
	void* GetNewRay();
	void ReturnRay(void* ray);
};


