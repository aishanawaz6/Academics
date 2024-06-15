#include <iostream>
#include "Time.h"
using namespace std;

int main() {

	Time t1(5,3,9);
	t1.getCurrentTime();
	int h, m, s;

	cout << "Enter Hours:   ";
	cin >> h;
	cout << "Enter Minutes : ";
	cin >> m;
	cout << "Enter Seconds : ";
	cin >> s;

	t1.sethours(h);
	t1.setminutes(m);
		t1.setseconds(s);
	t1.getCurrentTime(); 











	system("pause");
	return 0;
}