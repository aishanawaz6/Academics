#include <iostream>
using namespace std;
char** AllocateMemory(int& rows, int& cols){
	cout<<"enter rows: ";
	cin>>rows;
	cout<<"enter coloumns: ";
	cin>>cols;


	char **arr=new char * [rows];
	for (int i=0;i<rows;i++){
		arr[i]=new char [cols];
	}

	return arr;


}

void InputMatrix(char** matrix, const int rows, const int cols){
	cout<<"Enter values of matrix: "<<endl;
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
			cout<<"Enter value for row "<<i<<" ";
		cin>>matrix[i][j];
		}
	}
}

void DisplayMatrix(char** matrix, const int& rows, const int& cols){
	for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
		cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}


}

void dynamic (char **arr,int rows,int cols,char *&alphabets,char *&numbers,char*&specialchar,int &k,int&k2,int&k3) {
	alphabets=new char [50];
	numbers=new char [50];
	specialchar=new char [50];
 k=0,k2=0,k3=0;
	for (int i=0;i<rows;i++)
	{	for (int j=0;j<cols;j++)
	{
if (arr[i][j]>=65 && arr[i][j]<=122)
{
alphabets[k]=arr[i][j];
k++;
}
	if (arr[i][j]>=0 && arr[i][j]<=9)
		{
numbers[k2]=arr[i][j];
k2++;
}
	else
	{
specialchar [k3]=arr[i][j];
	}
	}

	}
	char*temp;
	temp=alphabets;
	alphabets=new char [k];
	alphabets=temp;
	temp=numbers;
	numbers=new char [k2];
	numbers=temp;
	temp=specialchar;
	specialchar=new char [k3];
	specialchar=temp;
	delete temp;
	temp=0;

}
void sortArray (char * alphabets,char*numbers,char*specialchar,int size1,int size2,int size3) {
	char temp;
	for  (int i=0;i<size1-1;i++){
		for (int j=0;j<size1-1-i;j++){
		if (alphabets [j]>alphabets [j+1])
		{
			temp =alphabets[j];
			alphabets[j]=alphabets[j+1];
			alphabets[j+1]=temp;
		}

		}


	}

		for  (int i=0;i<size2-1;i++){
		for (int j=0;j<size2-1-i;j++){
		if (numbers [j]>numbers [j+1])
		{
			temp =numbers[j];
			numbers[j]=numbers[j+1];
			numbers[j+1]=temp;
		}

		}


	}
			for  (int i=0;i<size3-1;i++){
		for (int j=0;j<size3-1-i;j++){
		if (specialchar[j]>specialchar [j+1])
		{
			temp =specialchar[j];
			specialchar[j]=specialchar[j+1];
			specialchar[j+1]=temp;
		}

		}


	}
			cout<<"Alphabets= ";
			for (int i=0;i<size1;i++)
					cout<<alphabets[i]<<" ";
			cout<<endl;
			cout<<"Numbers= ";
			for (int i=0;i<size2;i++)
					cout<<numbers[i]<<" ";
				cout<<endl;
				cout<<"SpecialCharacters= ";
			for (int i=0;i<size3;i++)
					cout<<specialchar[i]<<" ";
				cout<<endl;
}
void DeallocateMemory(char**matrix,char*numbers,char*alphabets,char*specialchar,int rows){



	for (int i=0;i<rows;i++)
		delete []matrix[i];
	delete []matrix;
	matrix=NULL;

	delete[] numbers;
	numbers=NULL;
	
	delete []alphabets;
	alphabets=NULL;
	
	delete []specialchar;
	specialchar=NULL;
}
int main () {

int rows, cols;
//take input from user for rows and cols
char** matrix = AllocateMemory (rows, cols);
InputMatrix(matrix, rows, cols);
DisplayMatrix(matrix, rows, cols);
// additional function calls
char*alphabets,*numbers,*specialchar;
int size1,size2,size3;
dynamic (matrix, rows, cols,alphabets,numbers,specialchar,size1,size2,size3);
sortArray (alphabets, numbers,specialchar,size1,size2,size3);

//deallocate memory
DeallocateMemory(matrix,numbers,alphabets, specialchar, rows);



	system("pause");
	return 0;

}

