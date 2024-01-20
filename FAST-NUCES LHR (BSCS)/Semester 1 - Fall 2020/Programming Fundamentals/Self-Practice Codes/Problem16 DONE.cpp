#include <iostream>
using namespace std;

int  main () 
{
	int h;

	cout<<"Pleas enter height of pattern: ";
	cin>>h;
	if (h<=9){
	

	for (int i=h,c=0;i>=0;i--)
	{
		for (int j=1;j<=i;j++)
      	cout<<j;
		for (int j=0;j<c*2;j++)
		cout<<" ";
		for (int j=i;j>0;j--)
		cout<<j;

		cout<<endl;
		c++;
	}
	
	
	
	
	
	
	}
	else
		cout<<"Invalid hight!"<<endl;








	system ("pause");
	return 0;
}