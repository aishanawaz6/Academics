#include <iostream>
using namespace std;

int main() {
	int a;
	cout <<"Please enter a number=";
	cin>> a;  

	if (a>=1 & a<=5)
		cout <<"Blue"<<endl;
	if  (a>=6 & a<=10)
		cout <<"Red"<<endl;
	if  (a>=11 & a<=15)
		cout <<"Green"<<endl;

	system("pause");
	return 0;
}