#include <iostream>
using namespace std;

int main () {
int f,s,b,p;
float area,price;
p=1;
	cout<<"Is it your birthday? (1 for yes and 2 for no): ";
	cin>>b;
	cout<<"Please enter pizza flavor (1 for Tikka, 2 for Fajita, 3 for Supreme): ";
	cin>>f;
		cout<<"Please enter pizza size (6,9 or 12 inches): ";
		cin>>s;
	
		if (s==6)
		{if (f==1)
		p=800;
	if(f==2)
	p=700;
	 if(f==3)
		p=1000;
	 	area= 3.14*s*s;
	price= p/area;
	 if (b==1)
cout<<"Price per square inch: "<<price*0.9<<" Rs\n";
		if(b==2)
cout<<"Price per square inch: "<<price<<" Rs\n";
		
		}
		if (s==9)
		{if (f==1)
		p=900;
 if(f==2)
	p=800;
	if(f==3)
		p=1200;
		area= 3.14*s*s;
	price= p/area;
		if (b==1)
cout<<"Price per square inch: "<<price*0.9;
		if(b==2)
cout<<"Price per square inch: "<<price;}
		if (s==12)
		{if (f==1)
		p=1000;
	if(f==2)
	p=900;
	if(f==3)
		p=1400;
		area= 3.14*s*s;
	price= p/area;
			if (b==1)
cout<<"Price per square inch: "<<price*0.9<<" Rs\n";
		if(b==2)
cout<<"Price per square inch: "<<price<<" Rs\n";}

	

	system("pause");
	return 0;
}