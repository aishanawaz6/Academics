#include<time.h>
#include<iostream>
using namespace std;

class myDate
{
	int d; 
	int m; 
	int y;

public:

	myDate(int d = 0, int m = 0, int y = 0)
	{ 
		this->d = d; 
		this->m = m; 
		this->y = y;
	} 

	int operator-(const myDate & d1)
	{
		int diff = 0;
		diff = (y-d1.y) * 365;
		diff = diff + (m-d1.m) * 30; 
		diff = diff + (d-d1.d); 
		return diff;
	}

	friend ostream & operator <<(ostream & out, const myDate & d)
	{ 

		out << d.d << "-" << d.m << "-" << d.y;	
		return out; 
	}

	int getday()
	{
		return d; 
	}

	int getmonth()
	{
		return m;
	}

	int getyear()
	{
		return y;
	}
	bool operator >=( const myDate & dt)
	{
	if (d>=dt.d &&m>=dt.m && y>=dt.y)
		return true;
	else
		return false;
	
	}
	bool operator <=( const myDate & dt)
	{
	return !(operator >=(dt));
	
	}
	myDate nextDay ()
	{
	d=d+1;
	return *this;
	}
		myDate nextWeek ()
	{
	d=d+7;
	return *this;
	}
			myDate nextMonth()
	{
	m=m+1;
	return *this;
	}
};



class MyTime
{
private :
	int hour;
    int minute;
    int second;
public :
    //constructor with default value 0
    MyTime(int h = 0, int m  = 0, int s = 0);
    //setter function 
    void setTime(int h, int m, int s);
    //print description of object in hh:mm:ss
    friend ostream & operator <<(ostream & out, const MyTime & t);
    //compare two time object
    bool operator == (const MyTime);
	int gethour();
	int getminute();
	int getsecond();
};
 
MyTime :: MyTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
}
 
void MyTime :: setTime(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;     
}        
 
ostream & operator <<(ostream & out, const MyTime & t)
{
	if (t.hour>12)
    cout << t.hour-12<< ":"<< t.minute << ":" << t.second << "\n";
	else
		    cout << t.hour << ":"<< t.minute << ":" << t.second << "\n";
	return out;
}
 
bool MyTime :: operator == (const MyTime otherTime)
{
    if(hour == otherTime.hour && 
        minute == otherTime.minute && 
        second == otherTime.second)
        return true;
    else
        return false;
}

int MyTime :: gethour()
{
	return hour;
}
int MyTime ::getminute()
{
	return minute;
}
int MyTime ::getsecond()
{
	return second;
}
 



//Global Date Function 
myDate CurrentDate()
{
	//If Function localtime() gives error, comment option 1 and use option 2
	
//-------------------------------Option 1 -------------------------------------------
	time_t now = time(0);
	struct tm * newtime = localtime(&now); 
	int curry = newtime->tm_year + 1900; 
	int currm = newtime->tm_mon + 1;
	int currd = newtime->tm_mday; 
	myDate d(currd, currm, curry); 
	return d;
	
//-------------------------------Option 2 -------------------------------------------
	//time_t now = time(0);
	//struct tm newtime;
	//localtime_s(&newtime,&now);
	//int curry = newtime.tm_year + 1900; 
	//int currm = newtime.tm_mon + 1;
	//int currd = newtime.tm_mday; 
	//myDate d(currd, currm, curry); 
	//return d;
}

class Task
{
	myDate Date;
	MyTime Time;
	string description;
public:	
	Task ()
	{}
	Task (int a,int b,int c,int d,int e,int f,string de):Date(a,b,c),Time(d,e,f)
	{
		description=de;
	}
	Task(Task*t)
	{
	Date=t->Date;
	Time=t->Time;
	description=t->description;
	}
	myDate getDate()
	{
	return Date;
	
	}
	virtual void print() //print function
	{
cout<<"Date: "<<Date;
	cout<<" Time: "<<Time;
	cout<<"Description: ";
	for (int i=0;description[i]!='\0';i++)
	cout<<description[i];
	cout<<endl;
	}
	
};

class OneTime: public Task
{
private:
	//no private attributes
public:
	OneTime(int a,int b,int c,int d,int e,int f,string de):Task (a, b, c, d, e, f,de){};
};

class Recurring: public Task,public myDate
{
private:
	int repitition_gap;		//Daily task? or weekly? or monthly?
public:
	Recurring (int a,int b,int c,int d,int e,int f,string de,int rg):Task (a, b, c, d, e, f,de){
	repitition_gap=rg;
	};
	void PrintNextDay()	//Print the date when it'll re-occur. In case of Daily, prints next date; for weeklym prints date of next week, for monthly, prints date of next month
	{cout<<"Your Next Day will be: ";
	if (repitition_gap==1)
		cout<<nextDay();
	else
		if (repitition_gap==2)
	cout<<nextWeek();
		else
			if (repitition_gap==3)
				cout<<nextMonth();
	}
};


class DailyList
{
private:
	Task**ListOfTasks;		//Lists of tasks for that day. Should it be a pointer? an object? decide yourself
	int numOfTasks;
	int capacity;				//max tasks a day can hold. set it to 2 per day.
public:
	DailyList ()
	{
	ListOfTasks=NULL;
 numOfTasks=0;
	 capacity=2;

	}
	DailyList (int nTasks)
	{
	ListOfTasks=new Task*[nTasks];
	 numOfTasks=nTasks;
	 capacity=2;
	
	}
	int getnumofTask()
	{
	return numOfTasks;
	}
	int getCap()
	{
	return  capacity;	
	}
};

class ToDoList : public DailyList
{
	DailyList**Year2021;		//Year2021 is the collection of DailyList for all 12 months. Should it be a pointer? an object? what will be its type?
	Task**t;
	int counter;
public:
	ToDoList()
	{
		counter=0;
		Year2021=new DailyList*[12];
			for(int i=0;i<12;i++)
	{
			if(i==1 || i==3 || i==5||i==7||i==8||i==10||i==12)
			Year2021[i]=new DailyList[31];
			else if (i==4||i==6||i==9||i==11)
				Year2021[i]=new DailyList[30];
			else
				Year2021[i]=new DailyList[28];
		}
		 t=new Task*[getnumofTask()];
	}
	 void AddTask(Task * T) //Add task to said date in calander
	 {
	 
	 if (counter<getCap())
	 {
	 t[counter]=T;
	 counter++;
	 }
	 else
		 cout<<"Capacity Exceeded"<<endl;}

	void GetSchedule(myDate Starting, myDate Ending)			//print all tasks that are between 2 dates.
	{
		int limit=Starting-Ending;
		for (int i=0;i<counter;i++)
		{
			if(t[i]->getDate()>=Starting &&t[i]->getDate()<=Ending)
		t[i]->print();
		}
	}
};


