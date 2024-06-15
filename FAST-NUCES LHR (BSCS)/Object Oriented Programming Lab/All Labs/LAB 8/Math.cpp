#include <iostream>
#include "Math.h"
using namespace std;


Math :: Math () 
{
	this->name="January";
	this->monthNumber=1;

}
Math :: Math (Math&m) 
{
this->name=m.name;
this->monthNumber=m.monthNumber;


}
Math  :: Math(string n)
{
this->name=n;
if (n=="January")
	this->monthNumber=1;

	else
		if (n=="February")
	this->monthNumber=2;
		else
			if (n=="March")
	this->monthNumber=3;
			else
				if (n=="April")
	this->monthNumber=4;
				else
					if (n=="May")
	this->monthNumber=5;
					else
						if (n=="June")
	this->monthNumber=6;
						else
							if (n=="July")
this->monthNumber=7;
							else

							if (n=="August")
	this->monthNumber=8;
							else
								if (n=="September")
	this->monthNumber=9;
	else
								if (n=="October")
	this->monthNumber=10;
	else
								if (n=="November")
									this->monthNumber=11;
										else
								if (n=="December")
	this->monthNumber=12;
	

}
Math Math:: operator ++ (int)
{
	Math n;
	if (this->monthNumber<12)
	{
		n.monthNumber=this->monthNumber++;
		if(n.monthNumber==2)
		n.name="February";
		else
			if(n.monthNumber==3)
		n.name="March";
		if(n.monthNumber==4)
		n.name="April";
		if(n.monthNumber==5)
		n.name="May";
		if(n.monthNumber==6)
		n.name="June";
		if(n.monthNumber==7)
		n.name="July";
		if(n.monthNumber==8)
		n.name="August";
		if(n.monthNumber==9)
			n.name="September";
			if(n.monthNumber==10)
				n.name="October";
				if(n.monthNumber==11)
					n.name="November";
					if(n.monthNumber==12)
						n.name="December";
	
	
	}
	else
	{	n.monthNumber=1;
	n.name="January";

	}
	return n;
}
Math Math :: operator ++ ()
{

	
	Math n;
	if (this->monthNumber<12)
	{
		n.monthNumber=++this->monthNumber;
		if(n.monthNumber==2)
		n.name="February";
		else
			if(n.monthNumber==3)
		n.name="March";
		if(n.monthNumber==4)
		n.name="April";
		if(n.monthNumber==5)
		n.name="May";
		if(n.monthNumber==6)
		n.name="June";
		if(n.monthNumber==7)
		n.name="July";
		if(n.monthNumber==8)
		n.name="August";
		if(n.monthNumber==9)
			n.name="September";
			if(n.monthNumber==10)
				n.name="October";
				if(n.monthNumber==11)
					n.name="November";
					if(n.monthNumber==12)
						n.name="December";
	
	
	}
	else
	{	n.monthNumber=1;
	n.name="January";

	}
	return n;

}

Math Math  ::  operator --(){
		
	Math n;
	if (this->monthNumber>1)
	{
		n.monthNumber=--this->monthNumber;
		if(n.monthNumber==2)
		n.name="February";
		else
			if(n.monthNumber==3)
		n.name="March";
		if(n.monthNumber==4)
		n.name="April";
		if(n.monthNumber==5)
		n.name="May";
		if(n.monthNumber==6)
		n.name="June";
		if(n.monthNumber==7)
		n.name="July";
		if(n.monthNumber==8)
		n.name="August";
		if(n.monthNumber==9)
			n.name="September";
			if(n.monthNumber==10)
				n.name="October";
				if(n.monthNumber==11)
					n.name="November";
					if(n.monthNumber==12)
						n.name="December";
	
	
	}
	else
	{	n.monthNumber=12;
	n.name="December";

	}
	return n;
}
	Math Math ::  operator --(int)
	{
	
	
	
	Math n;
	if (this->monthNumber>1)
	{
		n.monthNumber=this->monthNumber--;
		if(n.monthNumber==2)
		n.name="February";
		else
			if(n.monthNumber==3)
		n.name="March";
		if(n.monthNumber==4)
		n.name="April";
		if(n.monthNumber==5)
		n.name="May";
		if(n.monthNumber==6)
		n.name="June";
		if(n.monthNumber==7)
		n.name="July";
		if(n.monthNumber==8)
		n.name="August";
		if(n.monthNumber==9)
			n.name="September";
			if(n.monthNumber==10)
				n.name="October";
				if(n.monthNumber==11)
					n.name="November";
					if(n.monthNumber==12)
						n.name="December";
	
	
	}
	else
	{	n.monthNumber=12;
	n.name="December";

	}
	return n;}
	void Math:: print ()
	{

		cout<<"Month: "<<this->monthNumber<<endl;
		cout<<"Name: "<<this->name<<endl;

	}