#include <iostream>
using namespace std;

int main() {
	int a,b,c;
	cout <<"Please enter a number=";
	cin>> a;
	cout <<"Please enter second number=";
	cin>> b;
	cout <<"Please enter third number=";
	cin>> c;
	
	if ( a>b & a>c )
		cout <<a<<endl;
	if (b>c & b>a)
		cout <<b<<endl;
	if (c>a & c>b)
		cout <<c <<endl;
	system("pause");
	return 0;
}