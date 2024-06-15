#include <iostream>
using namespace std;

int main () {
	int z;
	cout <<"Please enter an year: ";
	cin>>z;
	if (( (z%4==0) && (z%100 !=0) )|| (z%400==0) )
		cout<<"It is an leap year! ";
	else
		cout<<"It is not an leap year! ";

	system("pause");
	return 0;
}