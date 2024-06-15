#include <string>
#include <iostream>
using namespace std;
Student::Student()
{
marks=0;
grade='A';
rollnum="none";
}
int Student:: getmarks()
{return marks;
}
char Student:: getgrade() {
return grade;
}
string Student:: getrollnum()
{
return rollnum;
}
void Student:: setmarks(int m){
marks=m;
}
void Student::setgrade(char g)
{
grade=g;
}
void Student:: setrollnum (string rn){
rollnum=rn;
}
