#include<time.h>
#include<iostream>
#include "Q2.h"
using namespace std;



int main()
{
	//Task T1 (12,06,2021, 08,0,0,);		//Design task class such that this line gives error
	OneTime T1 (23,06,2021, 21,0,0, "Prepare for OOP Lab Final"); //Task for 18 06 2021 at 09:00:00 pm
	OneTime T2 (26,06,2021, 14,0,0, "OOP Lab Final");
	Recurring T3(18,06,2021,13,0,0,"Lunch Break", 1);		//1 means it'll recurr every day.
	OneTime T4(26,06,2021, 16,0,0, "Post Exam Party");
	OneTime T5(26,06,2021, 19,0,0, "Dinner with Friends");
	
Task * T[3];
	T[0]=&T1;
	T[1]=&T2;
	T[2]=&T3;

	ToDoList MyList;
	
	for(int i=0;i<3;i++)
	{
		T[i]->print();
		MyList.AddTask(T[i]);
	}
	
	MyList.AddTask (&T4);
	MyList.AddTask (&T5);		//Must not be able to add third task on same day as capacity is of 2 tasks
	
	myDate D1(06, 06,2021);
	myDate D2(24, 06, 2021);
	
	
MyList.GetSchedule(D1, D2);
	system("pause");
	return 0;
}

//Following lines might help you save some time
//		for(int i=0;i<12;i++)
//		{
//			if(i==1 || i==3 || i==5||i==7||i==8||i==10||i==12)
//				Year2021[i]=new DailyList[31];
//			else if (i==4||i==6||i==9||i==11)
//				Year2021[i]=new DailyList[30];
//			else
//				Year2021[i]=new DailyList[28];
//		}