#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person
{
private:
	Person A;
double cgpa;
public:
	Student ()
	{
	cgpa=0;
	}
	Student (const char*f,const char*l,int a,double c):A (f,l,a)
	{
		cout<<"Student() called"<<endl;
	cgpa=c;
	}
	void setcgpa(double c)
	{
	cgpa =c;
	}
	double getcgpa ()
	{
	return cgpa;
	}
	void SPrint()
	{
		Person :: Print();
		cout<<"cgpa: "<<cgpa<<endl;
	}
	~Student() 
	{
    cout <<"~Student() called"<<endl;
	}
};