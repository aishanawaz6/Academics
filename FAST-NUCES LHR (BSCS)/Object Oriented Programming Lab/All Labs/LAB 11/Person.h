#pragma   once
#include <iostream>
using namespace std;

class Person 
{
private :
	char* first_name;
	char *last_name;
	protected:
	int age;
public:
	Person (const char*fn=NULL,const char*ln=NULL,int a=0) 
	{
		cout<<"Person() called"<<endl;
		int i=0;
		first_name=new char [strlen(fn)+1];

		for (i=0;fn[i]!='\0';i++)
		{
			first_name[i]=fn[i];
		
		}
		first_name[i]='\0';
		int j;
		last_name=new char [strlen(ln)+1];
		for (j=0;ln[j]!='\0';j++)
		{
		
		last_name[j]=ln[j];
		}
		last_name[j]='\0';
	age=a;
	}
	void setfname(char*f)
	{
	first_name=f;
	}
	void setlname(char*l)
	{
	last_name=l;
	}
	void setage(int ag)
	{
		age=ag;
	}
	char* getfname(){
		return first_name;
	}
	char* getlname(){
		return last_name;
	}
	int getage()
	{
	return age;
	}
	void Print() 
	{
		cout<<first_name<<" "<<last_name<<" is "<<age<<" years old."<<endl;
	}
~Person()
{
cout <<"~Person() called"<<endl;
delete []first_name;
delete []last_name;
first_name=NULL;
last_name=NULL;
}
};