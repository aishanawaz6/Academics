#include <iostream>
using namespace std;

int  main () {
	int n,q=1,x=0,y=1,c=0;
	cout<<"Please enter an number: ";
cin>>n; 
cout<<"Fibonacci sequence: "<<x<<","<<y<<",";
c=x+y;
while (q<=(n-2))
{cout<<c<<",";
x=y;
y=c;
c=x+y;
q=q+1;
}
cout<<endl;

	system("pause");
return 0;
}