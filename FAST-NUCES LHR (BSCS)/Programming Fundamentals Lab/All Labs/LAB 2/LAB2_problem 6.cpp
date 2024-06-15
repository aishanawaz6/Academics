#include <iostream>
using namespace std;

int main() {
	int a,b;
	cout <<"Please enter a number=";
	cin>> a;
	cout <<"Please enter another number=";
	cin>> b;
	if (a>b)
		cout<<"Ascending order is="<< b<<"," <<a;
	else 
		cout << "Ascending order is="<<a<<","<< b;
	system("pause");
	return 0;
}