#include <iostream>
using namespace std;

float main () {
	int a,b,c;
	cout<<"Please enter a: ";
	cin>> a;
	cout<<"Please enter b: ";
		cin>> b;
	cout<<"Please enter c: ";
		cin>> c;
	if	((a*b+2>21 || !(c==b/2)) && (c>13))
		cout <<"True";
	else cout <<"False";
	system("pause");
	return 0;
}