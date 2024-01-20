#include <iostream>
using namespace std;


int main () {
	int rows,j=1,coloumns=1;
cout<<"Enter number of rows (5-20) : ";
cin>>rows;

if (rows>=5 && rows<=20) 
{
	while (coloumns<=rows) {

		while (j<=coloumns) {
			cout<<"*";
			j++;
		}
		j=1;
		cout<<endl;
		coloumns++;
	}

}
else
	cout<<"Invalid input"<<endl;

	system ("pause");
	return 0;
}