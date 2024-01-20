#include <iostream>
using namespace std;

 void counter () {

	int static counter=1;
	
	cout<<counter++;
}



int main () {
	int a,b,k=1;
	cout<<"Please enter the first value: ";
	cin>>a;
	cout<<"Please enter the second value: ";
	cin>>b;
	while (k!= -1)
	{
		cout<<"Function is called ";
		counter();
			cout<<" time"<<endl;
cout<<"Sum is = "<<a+b<<endl;
cout<<"Press any digit key to continue or -1 to exist"<<endl;
cin>>k;
if (k!=-1)
{cout<<"Please enter the first value: ";
	cin>>a;
	cout<<"Please enter the second value: ";
	cin>>b;}
else break;
	}
	system("pause");
	return 0;
}


