#pragma once
#include <iostream>
#include "Person.h"
using namespace std;

class Faculty : public Person
{
	Person A;
int course_count;
int num;
public :

	Faculty (char*f,char*l,int a,int c=0,int n=0) : A(f,l,a)
	{
		cout<<"Faculty() called"<<endl;
		course_count=c;
	    num=n;
	}
	void	setcoursecount (int cc)
	{
		course_count=cc;
	}
int getcoursecount()
{
return course_count;
}
void setnum(int n)
{
num=n;
}
int getnum ()
{
return num;
}
~Faculty()
{
cout <<"~Faculty called"<<endl;
}
};