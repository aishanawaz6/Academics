
class Time {

private : 
	int hours;
	int minutes;
	int seconds;
public : 
	Time();
	Time(int hrs,int min,int sec);
	Time sethours(int hr);
	Time setminutes(int m);
	Time setseconds(int s);
	Time getCurrentTime();
	Time getseconds();
	Time getminutes();
	Time gethours();
};
