#pragma once
#include <iostream>
#include "Student.h"
using namespace std;


class Graduate : public Student {
private :
Student A;
	char*thesis_t;
public:
Graduate (char*f,char*l,int a,double cg,char *thesist=NULL):A (f,l,a,cg)
	{
		cout<<"Graduate() called"<<endl;
		thesis_t=thesist;
	}
~Graduate()
{
      cout <<"~Graduate() called"<<endl;
 //     delete thesis_t;
}
void setthesist(char*s)
{
thesis_t=s;
}
char* thesis_t(char*tt)
{
	thesis_t=tt;
}
};