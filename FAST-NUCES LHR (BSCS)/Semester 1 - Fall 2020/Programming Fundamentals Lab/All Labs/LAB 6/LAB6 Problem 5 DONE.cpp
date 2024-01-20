#include <iostream>
using namespace std;

int main () {
	int length,width,j=1,i=1;
	cout<<"Enter Length: ";
	cin>>length;
	cout<<"Enter Width: ";
	cin>>width;


	do {cout<<endl;
	i++;
	j=1;
	do {cout<<"*";
j++;
	} while (j<=width);
	
	}while (i<=length);

	system ("pause");
	return 0;

}