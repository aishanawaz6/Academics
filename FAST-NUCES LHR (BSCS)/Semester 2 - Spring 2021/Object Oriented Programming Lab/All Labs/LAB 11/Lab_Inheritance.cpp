#pragma once
#include <iostream>
#include "Undergraduate.h"
#include "Faculty.h"
#include "Person.h"
#include "Student.h"
using namespace std;

int main ()
{
	Student a("Ted","Thompson",22,3.91);
	//Faculty b("Richard","Karp",45,2,420);
	Person a2("Aisha","Nawaz",19);
	a2.Print();
	a.SPrint();

system ("pause");
return 0;
}
/*
Output for Exercise 5:

Person() called
Person() called
Person() called
Person() called
Student() called
Undergraduate() called
Person() called
Person() called
Faculty() called
Press any key to continue . . .
~Faculty called
~Person() called

*/