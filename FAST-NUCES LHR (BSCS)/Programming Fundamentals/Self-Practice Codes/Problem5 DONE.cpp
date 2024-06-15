#include <iostream>
using namespace std;



int main () {
int n1,n2,sum,product=1;

do{ 

cout<<"Enter number 1: ";
cin>>n1;
cout<<"Enter number 2: ";
cin>>n2;
sum=n1+n2;
product=product*n1*n2;

} while(sum%2==0);

cout<<"Product = "<<product<<endl;

	system ("pause");
	return 0;
}