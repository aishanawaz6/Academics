#include <iostream>
using namespace std;

int main () {
const int size=5;
float array[size],temp;

	for (int i=0; i<size;i++)
		cin>>array[i];
	cout<<"The Median of ";
	for (int i=0;i<size;i++)
	{
		cout<<array[i];
		if (i!=size-1)
			cout<<" , ";
		else
			cout<<" & ";
	}

	for (int i=0;i<size-1;i++)
	{
		for (int j=0;j<size-i-1;j++)
			{
				if (array[j]>array[j+1])
				{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
				}
		    }
	}
	
	 cout<<" is "<<array[size/2]<<endl;


	system("pause");
	return 0;
}