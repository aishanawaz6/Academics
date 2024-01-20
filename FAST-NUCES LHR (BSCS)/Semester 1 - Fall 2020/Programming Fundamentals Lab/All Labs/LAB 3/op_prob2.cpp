#include <iostream>
using namespace std;

float main () {
	float x,y,z;
	cout<<"Please enter value of x: ";
	cin>>x;
	cout<<"Please enter value of y: ";
	cin>>y;
	cout<<"Please enter value of z: ";
	cin>>z;
	if (( (x>y) || (x==5)) && ((x<=z) || !(z==1)))
		 cout << "flag is 1\n";

	else cout <<"flag is 0\n";
	system("pause");
	return 0;
}