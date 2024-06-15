#include <iostream>
using namespace std;

int main () {
	int x,y;
	cout<<"Please enter x-coordinate: ";
	cin >>x;
	cout<<"Please enter y-coordinate: ";
	cin >>y;
	if (x>=0 && y>=0)
		cout <<"Coordinate point lies in first quadrant";
		if (x<0 && y>=0)
	cout <<"Coordinate point lies in second quadrant";
			if (x<0 && y<0)
	cout <<"Coordinate point lies in third quadrant";
				if (x>=0 && y<0)
	cout <<"Coordinate point lies in fourth quadrant";

	system("pause");
	return 0;

}