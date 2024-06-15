#include <iostream>
using namespace std;

int main () 
{
	int digit,value,num,rem,i=0;
	bool flag=false;
	cout<<"Please enter a value : ";
	cin>>value;
	cout<<"Please enter a digit : ";
	cin>>digit;
	num=value;
	while (num!=0)
		{
			rem=num%10;
			num=num/10;
			i++;
			if (rem==digit)
			{
				flag=true;
				    if (i==1)
					cout<<"Units"<<endl;
				else
				    if (i==2)
					cout<<"Tens"<<endl;
				else
					if (i==3)
					cout<<"Hundreds"<<endl;
				else
				    if (i==4)
					cout<<"Thousands"<<endl;
				else
					if (i==5)
				    cout<<"Ten Thousands"<<endl;
				else
					if (i==6)
					cout<<"Hundred Thousands"<<endl;
				else
					if (i==7)
					cout<<"Millions"<<endl;
			}


		}
	if (flag==false)
		cout<<"Sorry digit not found!"<<endl;

		
	system ("pause");
	return 0;
}