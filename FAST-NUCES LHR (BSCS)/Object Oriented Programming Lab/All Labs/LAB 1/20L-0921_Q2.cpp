#include <iostream>
using namespace std;

int main () {

	int x,y;
	int *ptr;
	int *qtr;
	cout<<"Enter value of x: ";
	cin>>x;
	ptr=&x;
	cout<<"Enter value of y: ";
	cin>>y;
	qtr=&y;

	cout<<"Sum of X and Y is : "<<*ptr+*qtr<<endl;







	system ("pause");
	return 0;
}