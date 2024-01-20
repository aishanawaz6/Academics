#include <iostream>
using namespace std;
double factorial (int n);
double power (double x, int y);

int main () {
	int n;
	double x, value,sin=0;

	cout<<"Please enter the value of angle x : ";
	cin>>x;
	cout<<"Please enter the value of n: ";
	cin>>n;

	int j=2;
	for (int i=1;i<=n;i=i+2)
	{
		sin = sin + (power(-1,j))*(power(x,i)/factorial(i));
		j++;

	}
		cout<<"sin(x) = "<<sin<<endl;;
	system ("pause");
	return 0;
}


double factorial (int n) {
	int e,s=1;
	for(e=1;e<=n;e++)
	{
		s=e*s;

	} return s;
}


double power (double x, int y) {
	int r=x,u;
	for (u=1;u<y;u++)
	{x=r*x;
	}
	return x;
}
