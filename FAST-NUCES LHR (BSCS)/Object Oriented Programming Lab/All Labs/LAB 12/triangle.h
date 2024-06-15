#pragma once
#include "Shape.h"
class triangle : public Shape 
{


	public:
		triangle();
			triangle (float b,float h);
void area_calculator();
void area_calculator(float heightn, float basen);
private:
float base;
float height;

};