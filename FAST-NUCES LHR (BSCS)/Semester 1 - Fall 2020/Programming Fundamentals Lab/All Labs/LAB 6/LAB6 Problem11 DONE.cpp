#include <iostream>
using namespace std;

int main () {
	int n,num,remain,freq,rest;
	cout<<"Enter any number: ";
	cin>>num;
	for (n=0;n<10;n++) {
		cout<<"The frequency of "<<n<<" = ";
		freq=0;
		for (rest=num;rest>0;rest=rest/10)
		{ remain=rest%10;
		if (remain==n) 
			freq++;
		}
		cout<<freq<<endl;
	}
	system("pause");
    return 0;
}