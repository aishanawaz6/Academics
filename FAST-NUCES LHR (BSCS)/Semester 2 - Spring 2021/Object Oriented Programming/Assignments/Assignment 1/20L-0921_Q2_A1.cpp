#include <iostream>
using namespace std;

int main () {

		int rows,col;
	//User inputs for rows & coloumns
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
	
	// Creating output Array 1
		int **arr2 =new int* [rows];
	for (int i=0;i<rows;i++)
		arr2[i]=new int [2];
	
	//Initializing 2nd Coloumn of output Array 1
		for (int i=0;i<rows;i++)
	    { arr2[i][0]=0;
		 arr2[i][1]=1;
		}

// Creating 1st Coloumn of output Array 1
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<col;j++)
		{	if (arr[i][j]==1)
			arr2[i][0]++;
		}
	}

	//Priniting Output Array 1
	cout<<"output array 1: "<<endl;
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<2;j++)
			cout<<arr2[i][j]<<" ";
		cout<<endl;

	}
	cout<<endl;

	//intermediate 2Darray

		int **iarr =new int* [rows];
	for (int i=0;i<rows;i++)
		iarr[i]=new int [arr2[i][0]];

	int j2=0;
	cout<<"Intermediate Array: "<<endl;
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<col;j++)
			{
				if (arr[i][j]==1)
					{
						iarr[i][j2]=j+1;
						j2++;
				     }
		     }
j2=0;
	}

	//Printing intermediate  2D Array
	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<arr2[i][0];j++)
			cout<<iarr[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	//Declaring Output Array 2
	int **oarr =new int* [rows];
	for (int i=0;i<rows;i++)
		oarr[i]=new int [col];

	//intializing  Output Array 2
	for (int i=0;i<rows;i++)
		for (int j=0;j<col;j++)
			oarr[i][j]=0;

	for (int i=0;i<rows;i++)
	{
		for (int j=0;j<col;j++)
		{
			if (iarr[i][j]>0)
			oarr[i][iarr[i][j]-1]=1;
		}
	}

	// Printing output Array 2
	cout<<"Original Array/output array 2: "<<endl;
	for (int i=0;i<rows;i++)
	{
	for (int j=0;j<col;j++)
		cout<<oarr[i][j]<<" ";
     	cout<<endl;
	}

	//Deallocation of Arrays
	for (int i=0;i<rows;i++)
		{
			delete []arr[i];
			delete []arr2[i];
			delete []iarr[i];
			delete []oarr[i];
	    }
	delete [] arr;
	delete [] arr2;
    delete [] iarr;
	delete [] oarr;
	arr=NULL;
	arr2=NULL;
	iarr=NULL;
	oarr=NULL;


	system("pause");
	return 0;

}