#include <iostream>
using namespace std;

int main () 
{
	int h;
	char c;
	cout<<"Please enter height of pattern: ";
	cin>>h;
	cout<<"Please enter character for pattern: ";
	cin>>c;

	for (int i=0;i<h;i++)
	{	
		for (int j=0;j<=i;j++)
	    cout<<c<<" ";
	
		cout<<endl;
	}  

	for (int i=h;i>=0;i--)
	{
        for (int j=0;j<i;j++)
	    cout<<c<<" ";

		cout<<endl;
	}


	system ("pause");
	return 0;
}