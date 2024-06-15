#pragma once
#include "Shape.h"
#include <iostream>
using namespace std;



class Rectangle : public Shape
{

public:
	Rectangle ();
	Rectangle (float h,float w);
	void area_calculator();
	void area_calculator (float heightn,float widthn);
private :
	float height;
	float width;




};