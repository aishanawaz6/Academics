#pragma once
#include "Shape.h"
class Cylinder : public Shape
{

public:
	Cylinder();
	Cylinder (float r,float h);
void area_calculator();
void area_calculator(float radiusn, float heightn);

private:
float radius;
float height;

};