#include <iostream>
using namespace std;

int main () {



	int arr[5];
	int *ptr;
	ptr= arr;

	cout<<"Enter values of array elements : ";
	for (int i=0;i<5;i++)
		cin>>arr[i];

	cout<<"Now displaying addresses: "<<endl;
	cout <<"Using array: "<<endl;
	for (int i=0; i<5;i++)
		cout<<"Address of array element "<<i<< " is : "<<&arr[i]<<endl;

	cout <<"Using Pointer: "<<endl;
	for (int i=0; i<5;i++)
		cout<<"Address of array element "<<i<< " is : "<<ptr+i<<endl;







	system ("pause");
	return 0;

}