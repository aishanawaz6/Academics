#include <iostream>

using namespace std;

int main () {
	int array[20][20];
	for (int i=0;i<20;i++)
	{
		for (int j=0;j<20;j++)
		{
			array[i][j]=rand()%100;
		}
	}


	for (int i=0;i<20;i++)
	{
for (int j=0;j<20;j++)
{
	cout<<array[i][j]<<" ";
}
cout<<endl;
	}
	cout<<"_________SORTED____________________"<<endl;
	//Bubble Sort
	int temp;
	for (int ct=0;ct<20;ct++) {
	for (int i=0;i<19;i++)
	{
		for (int j=0;j<20-i-1;j++)
		{


			if (array[ct][j]>array[ct][j+1])
			{
			temp=array[ct][j];
			array[ct][j]=array[ct][j+1];
			array[ct][j+1]=temp;

			}



		}
	}


	}
	
	for (int i=0;i<20;i++)
	{
for (int j=0;j<20;j++)
{
	cout<<array[i][j]<<" ";
}
cout<<endl;
	}



	//End of Bubble sort

	 int check;
	for (int i=0;i<20;i++)
	{

    cout<<"Minimum of row "<<i+1<<" is = "<<array[i][0]<<" & ";
	cout<<"Maximum of row "<<i+1<<" is = "<<array[i][19];
	cout<<endl;

	}


	system("pause");
	return 0;
}