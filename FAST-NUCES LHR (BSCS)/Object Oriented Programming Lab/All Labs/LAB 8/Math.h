#include <string>
#include <iostream>
using namespace std;
class Math {
	string name;
	int monthNumber;
public :
	Math(); // Default Constructor 
	Math (Math&m);
	Math (string n);
	Math operator ++ (int);
	Math operator ++ ();
	Math operator --();
	Math operator --(int);
	void print();
};