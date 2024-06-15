#include <iostream>
using namespace std;
#include "Quadrilateral.h"

Quadrilateral :: Quadrilateral (int x1,int y1,int x2,int y2,int x3, int y3,int x4,int y4) : w(x1,y1),x(x2,y2),y(x3,y3),z(x4,y4)
	{
   cout<<"Quadrilateral () called"<<endl;
	}
Quadrilateral :: ~Quadrilateral(){
	cout<<"Quadrilateral () called"<<endl;
	}
void Quadrilateral ::	d print3 () {
	w.print1();
	x.print1();
	y.print1();
	z.print1();

	}