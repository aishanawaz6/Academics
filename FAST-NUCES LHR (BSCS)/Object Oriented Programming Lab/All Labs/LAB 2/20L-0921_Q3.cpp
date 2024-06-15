#include <iostream>
using namespace std;

int main () {
int size;

cout<<"Please enter size of array : ";
cin>>size;
	float *arri=new float [size];
	float *arr=new float [size];
cout<<"Please enter elements of array: ";

for (int i=0;i<size;i++)
	cin>>arri[i];


for (int i=0;i<size;i++)
	arr[i]=arri[i];

float temp;
for (int i=0;i<size-1;i++)
{
	for (int j=0;j<size-1-i;j++)
	{	if (arr[j]>arr[j+1])
		{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;

		}
	}

}

cout<<"second largest element is : "<<arr[size-2]<<endl;
cout<<"index of the second largest element is : ";
int index;
for (int i=0;i<size;i++)
{
	if (arri[i]==arr[size-2])
		index=i;

}
cout<<index<<endl;

	system ("pause");
return 0;
}