#pragma once
#include "Shape.h"
class Circle : public Shape
{

public:
	Circle();
	Circle (float r);
void area_calculator();
void area_calculator(float radiusn);

private:
float radius;




};