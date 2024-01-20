#include <iostream>
using namespace std;

int main () {
	int c,n,p=1;
	c=1;
	cout<<"Enter nth number: ";
	cin>>n;

	while (c<=n)
	{p=c*p;
	cout<<c<<"*";
	c=c+1;
	}
	cout<<"= "<<p<<endl;

	system("pause");
	return 0;
}