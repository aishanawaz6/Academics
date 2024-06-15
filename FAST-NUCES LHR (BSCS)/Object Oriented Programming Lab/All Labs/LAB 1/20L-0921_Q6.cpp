#include <iostream>
using namespace std;

int main () {

	float InArr[10];
	float ResArr[9];
	float *myptr=InArr;

	cout<<"Please enter values of InArr: ";
	for (int i=0;i<10;i++)
		cin>>InArr[i];

	for (int i=0;i<9;i++)
	ResArr[i] = InArr[i] + InArr[i+1];

	myptr=ResArr;

	cout<<"Displaying ResArray Now: "<<endl;
	for (int i=0;i<9;i++)
		cout<<*(myptr+i)<<" ";
	cout<<endl;








	system("pause");
	return 0;


}