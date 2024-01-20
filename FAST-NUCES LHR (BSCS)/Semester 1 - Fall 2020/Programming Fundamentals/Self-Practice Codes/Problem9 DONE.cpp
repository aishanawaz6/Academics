#include <iostream>
using namespace std;

int main () 
{
	float sum=0.0;
for (int i=1,j=0;j<300;i=i+2,j++)
{
	if (j%2==0)
		sum=sum+4.0/i;
	else
	sum=sum-4.0/i;

	if (j==99)
		cout<<"Value of pi after first 100 terms = "<<sum<<endl;
	else
		if (j==199)
		cout<<"Value of pi after first 200 terms = "<<sum<<endl;
	else
		if (j==299)
		cout<<"Value of pi after first 300 terms = "<<sum<<endl;
}



system("pause");
return 0;
}