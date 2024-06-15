#include <iostream>
using namespace std;

class MyArray {
private:
	int* arr;
	int size;

public:
	MyArray(int *a,int s)
	{
	this->arr=a;
	this->size=s;
	}

	int& operator[](const int i)
	{
	if (i>=0 && i<size)
		return this->arr[i];
	}

void print()
{
for (int i=0;i<this->size;i++)
	cout<<arr[i]<<" ";

cout<<endl;

}
};


int main()
{
	int f_array[] = { 2, 4, 6, 8};
	MyArray arr(f_array, 4);
	arr[2] = 6;
	arr.print();
	arr[3] = 12;
	arr[4] = 6;
//exception or not? no
	system ("pause");
	return 0;
}
