#include <iostream>
#include "20L-0921 Citizen.h"
using namespace std;

Citizen :: Citizen () {
	Name="Name";
	SurName="SurName";
	CNIC=12345678911234;
	Designation="Designation";
	Address="Address";
}
 Citizen ::Citizen  (string n,string sn,int c,string d,string a) {
	Name=n;
	SurName=sn;
	CNIC=c;
	Designation=d;
	Address=a;

}


 void Citizen :: input  () {
	 cout<<"Please Enter Name: ";
	getline (cin,Name);
	cout<<"Please Enter SurName: ";
getline (cin,SurName);
cout<<"Please Enter Designation: ";
getline (cin,Designation);
cout<<"Please Enter Address: ";
getline (cin,Address);
cout<<"Please Enter CNIC#: ";
cin>>CNIC;

}
void Citizen :: Print () {
	cout<<"Name: "<<Name<<endl;
	cout<<"SurName: "<<SurName<<endl;
	cout<<"CNIC: "<<CNIC<<endl;
	cout<<"Designation: "<<Designation<<endl;
	cout<<"Address: "<<Address<<endl;

}
void Citizen:: SetName (string n) {
	Name=n;

}
void Citizen:: SetSurName (string sn) {
	SurName=sn;

}
void Citizen:: SetCNIC (int c) {
	CNIC=c;

}
void Citizen:: SetDesigantion (string d) {
	Designation=d;

}
void Citizen:: SetAddress (string a) {
	Address=a;

}
void Citizen:: GetName () {
cout<<"Name: "<<Name<<endl;

}
void Citizen:: GetSurName () {
cout<<"SurName: "<<SurName<<endl;
}
void Citizen:: GetCNIC () {
cout<<"CNIC: "<<CNIC<<endl;
}
void Citizen:: GetDesigantion () {
cout<<"Designation: "<<Designation<<endl;
}
void Citizen:: GetAddress () {
cout<<"Address: "<<Address<<endl;
}


