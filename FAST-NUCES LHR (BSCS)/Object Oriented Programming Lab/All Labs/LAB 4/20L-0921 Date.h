#include <iostream>
using namespace std ;
 
class Date {
private:
	int Day;
	int Month;
	int Year;
public:
	Date ();
	Date (int d,int m, int y);
	void input ();
	void print ();

void SetDay(int d);
void SetMonth(int m);
void SetYear(int y);

void GetDay();
void GetMonth();
void GetYear();
};

