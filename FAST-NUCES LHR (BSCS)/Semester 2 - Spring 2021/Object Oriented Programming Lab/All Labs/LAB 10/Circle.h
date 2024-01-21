#include <iostream>
#include "Point.h"
using namespace std;
class Circle {
private:
	Point center;
	float radius;
	 Circle (int x,int y,float r) : center (x,y);
	void print ();
	~Circle ();

};