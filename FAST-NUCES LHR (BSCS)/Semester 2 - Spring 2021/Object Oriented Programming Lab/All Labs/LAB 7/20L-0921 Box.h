#include <iostream>
using namespace std;

class Box {

	double length;
	double breadth;
	double height;

public :
	static int objectCount; 	
	Box ();
	Box (double l,double b, double h);
	void setLength(double l);
	void setBreadth(double b);
	void setHeight(double h);
	double getLength ();
	double getBreadth ();
	double getHeight ();
	void print ();
static int getCount();
	double Volume();
	double Area();
	friend void print_surface_area (Box&b);
   friend void double_data_members (Box&b);
};


