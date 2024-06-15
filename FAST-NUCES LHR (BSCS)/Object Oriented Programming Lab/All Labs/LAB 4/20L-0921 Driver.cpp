#include <iostream>
#include "20L-0921 Date.h"
using namespace std;


int main () {

	Date date1;

date1.print();

Date independanceDay(14,8,2020);


independanceDay.print();
date1.input();
date1.print();

 Date xmasDay;
        xmasDay.print();
        xmasDay.SetDay(25);
        xmasDay.SetMonth(12);
	    xmasDay.SetYear(2018);
		xmasDay.GetDay();
        xmasDay.GetMonth();
	    xmasDay.GetYear();






system("pause");
return 0;
}