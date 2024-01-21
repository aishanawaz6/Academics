#include <iostream>
using namespace std;

int main () {

	int x,y;
	int *ptr;
	int *qtr;
		int *temp;
	cout<<"Enter value of x: ";
	cin>>x;
	ptr=&x;
	cout<<"Enter value of y: ";
	cin>>y;
	qtr=&y;

	temp=ptr;
	ptr=qtr;
	qtr=temp;

	cout<<"Value of X= "<<*ptr<<endl;
	cout<<"Value of Y= "<<*qtr<<endl;








	system ("pause");
	return 0;
}