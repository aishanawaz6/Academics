#include <iostream>
using namespace std;

float main() {
	float a,b,c,d,e,average;
	cout <<"Please enter marks of subjet a=";
	cin>> a;  
	cout <<"Please enter marks of subjet b=";
	cin>> b;  
	cout <<"Please enter marks of subjet c=";
	cin>> c;  
	cout <<"Please enter marks of subjet d=";
	cin>> d;  
	cout <<"Please enter marks of subjet e=";
	cin>> e;  
average = (a+b+c+d+e)/500*100;
if (average>80)
	cout<< "Grade is A"<<endl;
if (average>70 & average<=80)
	cout<< "Grade is B"<<endl;
if (average>60 & average<=70)
	cout<< "Grade is C"<<endl;
if (average>50 & average<=60)
		cout<< "Grade is D"<<endl;
if (average<=50)
	cout<< "Grade is F"<<endl;


	system("pause");
	return 0;
}