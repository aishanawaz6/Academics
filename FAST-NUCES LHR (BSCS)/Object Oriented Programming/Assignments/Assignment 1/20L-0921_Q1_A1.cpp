#include <iostream>
using namespace std;


int main () {
	int rows,col;
	//User inputs
	cout<<"Please enter number of rows of array : ";
	cin>>rows;
	cout<<"Please enter number of coloumns of array: ";
	cin>>col;
	cout<<"Please enter elements of array "<<endl;

	//Making 2D Dynamic Array
	int **arr =new int* [rows];
	for (int i=0;i<rows;i++)
		arr[i]=new int [col];

//Taking input for Array
	for (int i=0;i<rows;i++)
	{
		cout<<"Enter elements of row "<<i<<" : ";
         for (int j=0;j<col;j++)
	     cin>>arr[i][j];
	}
	

	// New array declarization
		int **arr2=new int *[rows];
		for (int i=0;i<rows;i++)
			arr2[i]=new int [col];

		int j2=0;
		cout<<"Resultant Array: "<<endl;

		//New array initialization and printing
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<col;j++)
			{
				if (arr[i][j]!=0)
				{
					arr2[i][j2]=arr[i][j];
				    cout<<arr2[i][j2]<<" ";
				    j2++;
				}
				j2=0;
	       	}
	cout<<endl;
	}


	//Deallocation of both the Arrays
	for (int i=0;i<rows;i++)
		{
			delete []arr[i];
			delete []arr2[i];
	    }
	delete [] arr;
	delete [] arr2;
	arr=NULL;
	arr2=NULL;


	system("pause");
return 0;
}