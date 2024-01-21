#include <iostream>
#include "Time.h"
using namespace std;


Time::Time() {

	hours = 0;
	minutes = 0;
	seconds = 0;
}
Time::Time(int hrs,int min,int sec) {


	hours = hrs;
	minutes = min;
	seconds = sec;


}
Time Time::sethours(int hr) {
	(hr >=0 && hr<=24) ? this->hours = hr : this->hours = 0;

	return *this;
}
Time Time::setminutes(int m) {
	(m >=0 && m <=60) ? this->minutes = m : this->minutes = 0;

	return *this;

}
Time Time::setseconds(int s) {
	(s >=0 && s <=60) ? this->seconds = s : this->seconds = 0;
	return *this;
}
Time Time::getCurrentTime() {
	this->gethours().getminutes().getseconds();

	return *this;
}
Time Time::getminutes() {
	cout << "Minutes : " << this->minutes << " ";
	return *this;
}
Time Time::getseconds() {
	cout << "Seconds : " << this->seconds << endl;
	return *this;
}
Time Time::gethours() {
	cout << "Hours : " << this->hours << " ";
	return *this;
}