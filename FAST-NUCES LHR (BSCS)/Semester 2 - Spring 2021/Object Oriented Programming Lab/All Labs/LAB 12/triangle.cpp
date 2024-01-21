#pragma once
#include <iostream>
#include "triangle.h"
using namespace std;


void triangle:: area_calculator ()
{
cout<<"Area : "<<0.5*base*height<<endl;
}
void triangle:: area_calculator (float heightn, float basen)
{
cout<<"Area : "<<0.5*basen*heightn<<endl;
}

	triangle :: triangle (float b,float h)
	{
	base=b;
	height=h;
	
	}
	
	triangle :: triangle ()
	{
	base=0;
	height=0;
	
	}