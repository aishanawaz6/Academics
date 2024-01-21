#include <iostream>
using namespace std;

void incrementer(int array[]) {

	 int *ptr=array;
	  for (int i=0;i<10;i++)
		array[i]=*(ptr+i)+3;
}

int main () {
      int array [10];
	  cout<<"Please enter elements of array : "<<endl;
	  for (int i=0;i<10;i++)
		  cin>>array[i];

	incrementer (array);

	  cout<<"After addition of three to each element: "<<endl;
	  for (int i=0;i<10;i++)
		  cout<<array[i]<<" ";
	  cout<<endl;

	system ("pause");
	return 0;

}