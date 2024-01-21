#include <iostream>
#include "Circle.h"
#include "Point.h"
using namespace std;


Circle ::Circle (int x,int y,float r) : center (x,y)
{
		this->radius=r;
		cout<<"Circle() called"<<endl;
	}
	void Circle :: print ()
	{
		center.Print1();
	cout<<"Radius : "<<this->radius<<endl;
	}
	Circle :: ~Circle ()
	{
	cout<<"~Circle() called"<<endl;
	}