#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include "q2header.h"
#include "q2define.cpp"
#include <fstream>
using namespace std;

int main (int argc,char*argv[])
{
pid_t ret_value;
ret_value=fork();
if(ret_value<0)
cout<<"Fork has failed"<<endl;
else
if(ret_value==0)
{

//Code for child process 
string fn;
fn=argv[1]; //Taking input from user for filename
int n;
n=3;
Student *s=new Student[n];
//Now reading data from file
ifstream file;
file.open(fn);
if (file.is_open())
{ 
string rn;
int m;
char g;
int i=0;
while (i<n) //Assuming data in file is kept in the format "Roll Number Marks Grade" & each student takes a line
{
file>>rn;
s[i].setrollnum(rn);
file>>m;
s[i].setmarks(m);
file>>g;

//Now updating grade
if (m>=80 && m<=100)
g='A';
else
if (m>=70 && m<=79)
g='B';
else
if (m>=60 && m<=69)
g='C';
else
if (m>=50 && m<=59)
g='D';
else
if (m<50)
g='F';


s[i].setgrade(g);
i++; //Next student
}
file.close();
}
else
cout<<"File not found!"<<endl;

//Now writing the updated data of each student (with grades assigned) to a file named output.txt
ofstream ofile;
ofile.open("output.txt");
if (ofile.is_open())
{
for(int i=0;i<n;i++)
{
ofile<<s[i].getrollnum()<<" ";
ofile<<s[i].getmarks()<<" ";
ofile<<s[i].getgrade()<<" ";
ofile<<endl;
}
ofile.close();
}
else
cout<<"Error writing data to output.txt "<<endl;

delete []s;
s=nullptr;
//child code ends here
}
else
cout<<"Parent process"<<endl;

return 0;
}

