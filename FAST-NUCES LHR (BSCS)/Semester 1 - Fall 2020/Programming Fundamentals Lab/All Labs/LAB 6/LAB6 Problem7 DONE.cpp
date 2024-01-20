#include <iostream>
using namespace std;

int main () {
	int i,j,k,n,sum=0;
	cout<<"Please enter value for N: ";
	cin>>n;
	

	for (i=0;i<=n;i++)
	{ 
		for (j=0;j<=i;j++);
		
		for (k=0;k<=j;k++);
	
	sum=sum+i*j*k;

	} 
	

	cout<<"Sum is : "<<sum<<endl;
	system("pause");
return 0;
}