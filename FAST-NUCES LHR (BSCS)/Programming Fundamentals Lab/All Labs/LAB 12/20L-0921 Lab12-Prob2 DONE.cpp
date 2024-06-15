#include <iostream>
using namespace std;

int sum (int array[],int summ,int j) {
	
	summ=summ+array[j];
	if (j==9)
		return summ;
	else
	if (j<10)
	{j++;
	return 	sum(array,summ,j);
	}
	



}




int main () {
	int arr[10];
	int summ=0;
	int j=0;
	cout <<"Please enter 10 elements of array: ";
	for (int i=0;i<10;i++)
		cin>>arr[i];
	cout<<"Sum: "<<sum(arr,summ,j)<<endl;





system("pause");
return 0;
}