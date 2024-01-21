#include <iostream>
using namespace std;


int main () {
const int a=5;
const int b=10;
const int c=12;

const int *ptr,*qtr,*rtr;
ptr=&a;
qtr=&b;
rtr=&c;
int med=*ptr;

if (*ptr>*qtr && *ptr<*rtr ||*ptr<*qtr && *ptr>*rtr)
	med=*ptr;
else
	if (*qtr<*ptr && *qtr>*rtr ||*qtr>*ptr && *qtr<*rtr)
		med=*qtr;
	else
		med=*rtr;




cout<<"Median = "<<med<<endl;

cout<<"-1 cannot be assigned to the median as the median is a constant value."<<endl;
cout<<"However, if the constant is removed from the int type variable that is median then -1 can be assigned easily."<<endl;















	system ("pause");
	return 0;
}