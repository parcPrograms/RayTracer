#pragma once
class Light
{
private:
	double brightnes[4] = {0,0,0,0}; //0=none 255=max bright
public:
	virtual double* GetBrightness() = 0;
	~Light() {};
};

