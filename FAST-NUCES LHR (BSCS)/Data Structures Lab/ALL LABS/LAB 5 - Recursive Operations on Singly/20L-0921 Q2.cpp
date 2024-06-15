#include <iostream>
using namespace std;
int product(int a, int b)
{
	if(b<0)
		b=b*-1;
	if (b!=0)
	return a+product(a,b-1);
	else
		return 0;

}
int main ()
{

	int a=15,b=-9;
	cout<<product(a,b)<<endl;


system("pause");
return 0;

}