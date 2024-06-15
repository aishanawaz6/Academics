#include <iostream>
using namespace std;
int gcd (int a,int b, int min, int i,int gc) {

	if (i<=min){
		if ((a%i==0) && (b%i==0))
		{	gc=i;
		i++;
		return gcd(a,b,min,i,gc); 
		}
		else{
			i++;
			return gcd(a,b,min,i,gc); 
		}
		}
	else
		return gc;


}

int main () {
	int a,b,min;
	int i=1;
		int gc=1;

	cout<<"Please enter two numbers: ";
	cin>>a>>b;
	if (a<b)
		min=a;
	else
		min=b;

	cout<<"GCD: "<<gcd(a,b,min,i,gc)<<endl;






	system ("pause");
	return 0;
}