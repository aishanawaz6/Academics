#include <iostream>
using namespace std;


int main () {

	int n;
	cout<<"Enter value of n: ";
	cin>>n;

int *ptr=new int[n];
int x=0,y=1,z=0;

ptr[0]=1;
for (int i=0;i<n;i++)
{
	
	z=x+y;
	ptr[i+1]=z;
	x=y;
	y=z;
}

for (int i=0;i<n;i++)
	cout<<ptr[i]<<" ";
cout<<endl;

delete[] ptr;
ptr=NULL;

	system ("pause");
	return 0;
}