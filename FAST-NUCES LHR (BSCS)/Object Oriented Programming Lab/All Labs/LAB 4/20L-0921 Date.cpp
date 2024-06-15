#include <iostream>
#include "20L-0921 Date.h"
using namespace std;


Date :: Date (){


		cout<<"Default Constructor Called"<<endl;
		Day = 01;
		Month =01;
		Year=1926;



}


Date :: Date (int d, int m,int y){


		cout<<"Overloaded Function Called"<<endl;
		Day = d;
		Month =m;
		Year=y;



}
void Date :: input () {
do 
	{cout<<"Please enter Day: ";
	cin>>Day;
	}while (Day>31 || Day<0);

	do {
		cout<<"Please enter Month: ";
		cin>>Month;
	}
	while(Month > 12 ||Month<0);

	cout<<"Please enter Year: ";
	cin>>Year;
}

void Date :: SetDay (int d) {
	if (d<=31 && d>0)
	Day=d;
	else
		cout<<"Invalid Day"<<endl;

}
void Date :: SetMonth (int m) {
	if (m<=12)
	Month=m;
	else
cout<<"Invalid Month"<<endl;
}
void Date :: SetYear (int y) {
	Year=y;
}

void Date ::  GetDay(){
	cout<<Day<<"/";
}
void Date ::  GetMonth(){
	cout<<Month<<"/";
}
void Date ::  GetYear(){
	cout<<Year<<endl;
}



void Date :: print () {
	cout <<Day<<"/"<<Month<<"/"<<Year<<endl;
}

