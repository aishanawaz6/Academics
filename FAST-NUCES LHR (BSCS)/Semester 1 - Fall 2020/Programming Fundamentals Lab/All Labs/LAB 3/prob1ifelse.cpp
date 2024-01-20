#include <iostream>
using namespace std;

int main () {
	int x,y,z;
	cout<<"Please enter first number: ";
	cin>>x;
	cout<<"Please enter second number: ";
	cin>>y;
	cout<<"Please enter third number: ";
	cin>>z;
	if (x>y && x>z)
		cout<<x;
	else if 	(y>x && y>z)
		cout<<y;
	else if (z>x && z>y)
		cout<<z;
	system("pause");
	return 0;
}