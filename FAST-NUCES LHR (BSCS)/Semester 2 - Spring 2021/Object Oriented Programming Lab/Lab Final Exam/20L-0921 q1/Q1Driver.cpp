#include <iostream>
#include "Q1.h"
using namespace std;

int main()
{
	int a[5]={1,0,1,1,0};
	int b[5]={0,1,1,0,1};
	Binary Num0;
	cin>>Num0;
	cout<<Num0;

	Binary Num1(a, 5);
	Binary Num2(b,5);

	Binary Num3= Num1 || Num2;
	cout<<Num3;				//prints 11111

	Binary Num4;
	Num4=Num1 && Num3;		
	cout<<Num4;				//prints 10110

	Num2= !Num1;
	cout<<Num2;				//prints 01001
	system("pause");
	return 0;
}