#include <iostream>
using namespace std;

int main () 
{
	int upper,lower,min;
	cout<<"Enter a fraction: ";
	cin>>upper;
	cout<<" / ";
	cin>>lower;

	if (upper<lower)
	    min=upper;
	else
	   min=lower;

	int ans=1;

	for (int i=2;i<=min;i++)
	{
		if (upper%i==0 && lower%i==0)
		{
          ans=i;
          break;
		}
	}
	cout<<"Reduced Fraction: "<<upper/ans<<" / "<<lower/ans<<endl;


	system ("Pause");
	return 0;
}