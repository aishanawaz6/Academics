#include <iostream>
using namespace std;

int main () {
	int i,j,n;
	cout<<"Please enter value of n: ";
	cin>>n;

	for (i=1;i<=n;i++) 
	{
		for (j=1;j<=n;j++) {
cout<<i*j<<" ";
		}
		cout<<endl;
	}


	system ("pause");
	return 0;
}