#include <string>
#include <iostream>
using namespace std;
class Student{
string rollnum;
int marks;
char grade;
public:
Student();
int getmarks();
char getgrade();
string getrollnum();
void setmarks(int m);
void setgrade(char g);
void setrollnum (string rn);
};