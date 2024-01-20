#include <iostream>
using namespace std;

float main () {
float h,w, bmi;
	cout <<"Height= ";
	cin>>h;
		cout <<"Weight in kilogram= ";
		cin>> w;
		if (h>0 && w>0)
		{ bmi=w/(h*h);
cout<<"BMI = "<<bmi<<endl;
if (bmi<18.5)
	cout<<"Underweight on BMI scale\n";
if (bmi<=24.9 && bmi>=18.5)
	cout<<"Normal on BMI scale\n";
if (bmi<=29.9 && bmi>=25)
		cout<<"Overweight on BMI scale\n";
if (bmi>=30)
	cout<<"Obese on BMI scale\n";}
		else 
			cout<<"Entered data is incorrect!\n";

	system("pause");
	return 0;
}