#pragma once
#include <iostream>
using namespace std;

class Shape 
{
protected:
	string type;
public:
	Shape ();
	Shape (string ty);
	virtual void area_calculator();

};