#include <iostream>
using namespace std;

int main () {
	int n,c,p,x;
	p=0;
	x=0;
c=0;
	cout <<"Please enter nth number: ";
	cin>>n;

	while (c<=n)
	{if (c%2==0)
	p=p+c;
	if (c%2!=0)
	x=x+c;
		c=c+1;
	}
	cout<<"Sum of evens = "<<p<<endl;
	cout<<"Sum of odds = "<<x<<endl;


	system("pause");
	return 0;
}