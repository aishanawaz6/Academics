#pragma once
#include <iostream>
#include "Circle.h"
using namespace std;


void Circle:: area_calculator ()
{
cout<<"Area : "<<3.142*radius*radius<<endl;
}

void Circle:: area_calculator (float radiusn)
{
cout<<"Area : "<<3.142*radiusn*radiusn<<endl;
}
Circle:: Circle (float r)
{
	radius =r;
}
Circle :: Circle ()
{
radius=0;
}