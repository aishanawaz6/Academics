#include <iostream>
using namespace std;

int main () {
	int t;
	cout<<"Please enter temperature in centigrade: ";
	cin>>t;
	if (t<0)
		cout <<"Freezing weather";
	else if (t>=0 && t<10)
		cout <<"Very Cold Weather";
		else if (t>=10 && t<20)
			cout <<"Cold Weather";
	else if (t>=20 && t<30)
		cout <<"Norm in Temp";
		else if (t>=30 && t<40)
cout <<"It's Hot";
		else if (t>=40)
cout <<"It's Very Hot";

	system("pause");
	return 0;
}