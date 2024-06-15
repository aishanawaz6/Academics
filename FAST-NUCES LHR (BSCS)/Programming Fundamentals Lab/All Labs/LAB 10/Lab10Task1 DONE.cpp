#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main () {
	
	string name,ad, dob,emp;
	string nam="Name: ", add="Address: ",dobb="DOB: ",empp="Employment Status: ";
	cout<<"Please enter your Name: "<<endl;
	cin>>name;
	cout<<"Please enter your Address (Do not enter spaces): "<<endl;
	cin>>ad;
	cout<<"Please enter your Date of birth (dd/mm/yyyy): "<<endl;
	cin>>dob;
	cout<<"Please enter your Employment status (Unemployed/Employed): "<<endl;
	cin>>emp;
	if (emp=="Unemployed"||emp=="Employed")
	{
		ofstream file("user info.txt");
		file<<nam<<name<<endl;
		file<<add<<ad<<endl;
		file<<dobb<<dob<<endl;
		file<<empp<<emp;
	ifstream fike("user info.txt");
		cout<<"Reading from file: "<<endl;
		fike>>nam>>name;
		fike>>add>>ad;
		fike>>dobb>>dob;
		fike>>empp>>emp;
	cout<<nam<<name<<endl;
		cout<<add<<ad<<endl;
			cout<<dobb<<dob<<endl;
				cout<<empp<<emp<<endl;
				
	fike.close();

	}





	else
	cout<<"Invalid Input!"<<endl;
	system("pause");
	return 0;
}