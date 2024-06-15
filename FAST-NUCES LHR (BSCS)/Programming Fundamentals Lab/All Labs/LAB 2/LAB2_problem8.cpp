#include <iostream>
using namespace std;

int main() {
	int a;
	cout <<"Please enter Test Score=";
	cin>> a;

	if ( a>=50 )
		cout <<"The test score has been passed!"<<endl;
	else 
		cout <<"The test has been failed!"<<endl;

	system("pause");
	return 0;
}