#include <iostream>
using namespace std;

int main () {
	int sides,i=1,j=1;
	cout<<"Please enter size of the side of a square : ";
	cin>>sides;
if (sides>=1 && sides<=20) 
{
while (j<=sides)
	 {	
		while (i<=sides)
		{
		if (i==1 || i==sides)
			cout<<"*";
		else 
			if (j==1 || j==sides)
			cout<<"*";
	else 
		cout<<" ";
		i++;
		}
		i=1;
		cout<<endl;
		j++;
	}
}
else
	cout<<"Invalid input!"<<endl;
	system ("pause");
	return 0;
}