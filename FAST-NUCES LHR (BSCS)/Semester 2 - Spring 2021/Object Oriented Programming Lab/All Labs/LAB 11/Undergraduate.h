#pragma once
#include <iostream>
#include "Student.h"
using namespace std;

class Undergraduate : public Student 
{
private:
	Student s;
char*fyp_name;
public:
	Undergraduate (char*f,char*l,int a,double cgp,char*fyp=NULL): s(f,l,a,cgp)
	{
		cout<<"Undergraduate() called"<<endl;
		fyp_name=fyp;
	}
	void setfyp(char*fyp)
	{
		fyp_name=fyp;
	}
	char* getfyp()
	{
	return fyp_name;
	}
	void Sprint()
	{
	Student:: SPrint();
	}
	~Undergraduate()
	{
cout <<"~Undergraduate() called"<<endl;
//delete fyp_name;
    }

};
