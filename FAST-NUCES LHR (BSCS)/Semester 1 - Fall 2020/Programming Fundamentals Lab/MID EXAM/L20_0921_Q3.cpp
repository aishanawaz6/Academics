#include <iostream>
using namespace std;

int main () {
	int n1,n2,min,max,r;
	cout<<"Please enter two numbers: ";
	cin>>n1>>n2;
	if (n1<n2)
	{min=n1;
	max=n2;
	}
	else 
		if (n1>n2)
			{min=n2;
	max=n1;}
	
	while (max>=min) {
			r=max-min;
		max=min;
		min=r;
	
	}
	cout<<"The GCD is : "<<max<<endl;

	system("pause");
	return 0;

}