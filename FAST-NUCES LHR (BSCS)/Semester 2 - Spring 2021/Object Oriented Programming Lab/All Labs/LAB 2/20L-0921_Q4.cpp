#include <iostream>
using namespace std;


int main () {
	int A[10],B[10],C[10];

	cout<<"Please enter elements of A: "<<endl;
	for (int i=0;i<10;i++)
cin>>A[i];
	cout<<"Please enter elements of B: "<<endl;
	for (int i=0;i<10;i++)
cin>>B[i];
	cout<<"Please enter elements of C: "<<endl;
	for (int i=0;i<10;i++)
cin>>C[i];

	int k=0,k2=0,k3=0;
	int **ptr= new int *[3];
	for (int i=0;i<3;i++)
		ptr[i]=new int [10];

	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
if (A[i]==B[j])
{
	ptr[0][k]=A[i];
		k++;
}

	}
		for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
if (B[i]==C[j])
{
	ptr[1][k2]=B[i];
		k2++;
}

	}
		for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
if (C[i]==A[j])
{
	ptr[2][k3]=C[i];
		k3++;
}

	}
		cout<<"Resultant 2D Array: "<<endl;
			for (int j=0;j<k;j++)
			cout<<ptr[0][j]<<" ";
		
		cout<<endl;
			for (int j=0;j<k2;j++)
			cout<<ptr[1][j]<<" ";
			
		cout<<endl;
				for (int j=0;j<k3;j++)
			cout<<ptr[2][j]<<" ";
				
		cout<<endl;
		
	system("pause");
	return 0;

}