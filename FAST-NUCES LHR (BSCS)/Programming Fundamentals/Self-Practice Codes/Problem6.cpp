#include <iostream>
using namespace std;

int main () {


	int stnum,last,i=0;
	
cout<<"Enter Starting Number : ";
cin>>stnum;
cout<<"Enter the number of elements in last row: ";
cin>>last;
int j=0;
while( i<last*2) 
{
	cout<<stnum+i<<" ";
		if (i==2+j){
	cout<<endl;

		}
	i++;
	
}
	system ("pause");
	return 0;
}