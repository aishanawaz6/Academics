#include <iostream>
using namespace std;


int main () {
          int x,i,a,n;
  cout<<"Please enter the value of x: ";
  cin>>x;
  cout<<x<<" ";
  for (i=0,a=x;a!=1;i++) 
 {
	 
if (a%2==0)
	 a=a/2;
else
   a=a*3+1;
cout<<a<<" ";

 }
  cout<<endl;
  cout<<"k= "<<i<<endl;


	system("pause");
	return 0;
}