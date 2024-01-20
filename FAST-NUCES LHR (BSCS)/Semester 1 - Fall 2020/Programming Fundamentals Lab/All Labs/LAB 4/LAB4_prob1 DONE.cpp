#include <iostream>
using namespace std;

int main () {
	int age,e,q;
	char g;
	cout<<"Please enter gender (m for male & f for female): ";
	cin>>g;
	 if (g=='m'|| g=='M')
		{cout<<"Please enter age: ";
	cin>>age;
	if (age<=25 )
		 cout<<"Not eligible for this job\n";
	if(age>25)
	{cout<<"Please enter qualification (1 for freshgraduate, 2 for ms and 3 for phd): ";
	cin>>q;
	cout<<"Please enter experience in years: ";
	cin>>e;
	
	 if (q==1)
	 cout<<"salary will be in the range 25-40K\n";
	 if (q==2)
	 {if (e>5)
cout<<"salary will be in the range 70k above\n";
if(e<5)
		 cout<<"salary will be in the range 40k to 70k\n";
	 }
		 if (q==3)
			{ if (e>5)
			cout<<"salary will be in the range 70k above\n";
			if(e<5)
				cout<<"salary will be in the range 40k to 70k\n";}}

	 }
	 if (g=='f'||g=='F')
		 cout<<"Not eligible for this job\n";

system("pause");
	return 0;
}
