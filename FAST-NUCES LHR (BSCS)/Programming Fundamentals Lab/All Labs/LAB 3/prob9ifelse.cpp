#include <iostream>
using namespace std;

int main () {
	int x,y,z;
		cout <<"Please enter angle x: ";
	cin>>x;
	cout<<"Please enter angle y: ";
		cin>>y;
	cout<<"Please enter angle z: ";
		cin>>z;
		z=x+y+z;
		if (z==180 && x != 0 && y!=0 && z!=0) 
			cout <<"Triangle is valid";
		else cout <<"Triangle is not valid";
	system ("pause");
	return 0;

}