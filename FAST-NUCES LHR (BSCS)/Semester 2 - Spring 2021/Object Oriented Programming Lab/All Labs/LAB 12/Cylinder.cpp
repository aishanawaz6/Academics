#pragma once
#include <iostream>
#include "Cylinder.h"
using namespace std;


void Cylinder:: area_calculator ()
{
cout<<"Area : "<<(2*3.142*radius*height)+(2*3.142*radius*radius)<<endl;
}
void Cylinder:: area_calculator (float radiusn,float heightn)
{
cout<<"Area : "<<(2*3.142*radiusn*heightn)+(2*3.142*radiusn*radiusn)<<endl;
}
	Cylinder:: Cylinder (float r,float h)
	{
	radius=r;
	height=h;
	
	}
		Cylinder:: Cylinder ()
	{
	radius=0;
	height=0;
	
	}