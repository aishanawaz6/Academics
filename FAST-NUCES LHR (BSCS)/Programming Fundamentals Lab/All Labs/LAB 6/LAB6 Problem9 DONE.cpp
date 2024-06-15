#include <iostream>
using namespace std;

int main () {
	int v1,v2,v3,v4;
	char oper;

	cout <<"Welcome to the 10-function Calculator!"<<endl;
	cout<<"Enter"<<endl;
	cout<<"+ For addition operation"<<endl;
	cout<<"- For subtraction operation"<<endl;
	cout<<"* For multiplication operation"<<endl;
	cout<<"/ For division operation"<<endl;
	cout<<"q To quit"<<endl;

	cout<<"-->";
	cin>>oper;
	if (oper== 'q')
			cout<<"Quit the menu"<<endl;
	else 
		if (oper!='+'&&oper!='-'&&oper!='/'&&oper!='*'&&oper!='q')  
		cout<<"Invalid Input"<<endl;
		else
	while (oper!='q') {
	
		if (oper=='+' || oper=='-' || oper=='*'|| oper=='/' )
	{cout<<"Enter the first value: ";
	cin>>v1;
	cout<<"Enter the second value (other than zero): ";
	cin>>v2;
	cout<<"Enter the third value: ";
	cin>>v3;
	cout<<"Enter the forth value (other than zero): ";
	cin>>v4;
	if (oper== '+')
	{
		if (v2==v4)
		{	cout<<"The numerator of result is "<<v1+v3<<" and denominator of result is ";
		cout<<v2<<endl;}
		else {
		cout<<"The numerator of result is "<<(v1*v4)+(v2*v3)<<" and denominator of result is "; 
			cout<<v2*v4
				<<endl; 
		}

	}
	else if (oper== '-')
	{
		if (v2==v4)
		{cout<<"The numerator of result is "<<v1-v3<<" and denominator of result is ";  
		cout<<v2<<endl;}
		else 

		{ 
		cout<<"The numerator of result is "<<(v1*v4)-(v2*v3)<<" and denominator of result is "; 
			cout<<v2*v4<<endl; 
		}

	}
	else	if (oper== '*')
		{
				cout<<"The numerator of result is "<<v1*v3<<" and denominator of result is "<<v2*v4<<endl;
		}
	else 	if (oper== '/')
	{
		cout<<"The numerator of result is "<<v1*v4<<" and denominator of result is "<<v2*v3<<endl;
	}
		}
		
	cout<<"-->";
			cin>>oper;
			if (oper=='q')
				cout<<"Quit the menu"<<endl;
			else
	 if (oper!='+'&&oper!='-'&&oper!='/'&&oper!='*'&&oper!='q')  
		cout<<"Invalid Input"<<endl;
	}
	system ("pause");
	return 0;
}