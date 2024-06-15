#include <iostream>
using namespace std;

int main () {
	int sides,i,j;
	cin>>sides;

	for (j=1;j<=sides;j++)
	 {	
		for (i=1;i<=sides;i++)
		{
		if (i==1 || i==sides)
			cout<<"*";
		else 
			if (j==1 || j==sides)
			cout<<"*";
	else 
		cout<<" ";

		}
		cout<<endl;
	}
	system ("pause");
	return 0;
}