#include <iostream>
#include "20L-0921 Box.h"
using namespace std;

int main () {

	Box b1;
	b1.setLength (2.5);
	b1.setBreadth(3.0);
	b1.setHeight(2.5);
	b1.print();
	cout<<"--------------------------"<<endl;

	Box b2;
	b2.print();
	b2.setLength(b1.getLength());
	b2.setBreadth(b1.getBreadth());
	b2.setHeight(b1.getHeight());
	b2.print();
	cout<<"--------------------------"<<endl;

	Box b3(2.8,3.0,5.6);
	b3.print();
	cout <<"b3 Area : "<<b3.Area()<<endl;
	cout<<"b3 Volume : "<<b3.Volume()<<endl;
	cout<<"--------------------------"<<endl;

	cout<<"Number of objects created : "<<Box :: getCount()<<endl;
	print_surface_area (b2);
	cout<<"--------------------------"<<endl;

	Box b4(2,2,2);
	b4.print ();
	double_data_members (b4);
	b4.print ();
	




system ("pause");
	return 0;
}

