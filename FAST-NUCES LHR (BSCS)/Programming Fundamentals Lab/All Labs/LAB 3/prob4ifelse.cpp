#include <iostream>
using namespace std;

int main () {
	int x;
	cout<< "Please enter an number: ";
	cin>> x;
if (x>0 && x<=9)
	cout << "Number of digit entered is 1";
else if (x>9 && x<100)
	cout << "Number of digits entered are 2";
else if (x>=100 && x<1000)
	cout << "Number of digits entered are 3";
else if (x>=1000 && x<10000)
	cout << "Number of digits entered are 4";
else if (x>=10000 && x<100000)
	cout << "Number of digits entered are 5";
else if (x>=100000 && x<1000000)
		cout << "Number of digits entered are 6";

	system("pause");
	return 0;

}