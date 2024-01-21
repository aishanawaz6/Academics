#include <iostream>
#include "fraction.h"
using namespace std;


fraction :: fraction () 
{
	this->num=0;
	this->denum=1;

}
fraction :: fraction (int n,int d) 
{
	this->num=n;
	this->denum=d;
}
 fraction :: fraction (fraction&f)
{
this->num=f.num;
this->denum=f.denum;

}
void fraction:: setnum (int n) 
{
	this->num=n;
}
void fraction :: setdenum (int d) 
{
	this->denum=d;
}
int fraction :: getnum () 
{
	return this->num;

}
int fraction :: getdenum () 
{
return this->denum;
}
void fraction:: operator!(void) const
{
	cout<<"fraction = ";
	cout<<this->num<<"/"<<this->denum<<endl;

}
 fraction fraction:: operator-(void) 
{
	this->num=this->num*-1;
	this->num=this->denum*-1;
	cout <<"Negative of fraction = "<<this->num<<"/"<<this->denum<<endl;
	return *this;

}
fraction fraction :: operator*(void)
{   int temp;
	temp=this->num;
	this->num=this->denum;
	this->denum=temp;
		cout <<"Reciprocal of fraction = "<<this->num<<"/"<<this->denum<<endl;
		return *this;
}
fraction& fraction::  operator+=(const fraction&f)
{
	fraction fn;
	if (this->denum==f.denum)
	{
	fn.num=this->num+f.num;
	fn.denum=this->denum;
	}
	else
	{
	fn.num=this->num*f.denum+this->denum*f.num;
	fn.denum=this->denum*f.denum;
	}
	return fn;
}
fraction& fraction :: operator-=(const fraction&f)
{
	fraction fn;
	if (this->denum==f.denum)
	{
	fn.num=this->num-f.num;
	fn.denum=this->denum;
	}
	else
	{
	fn.num=this->num*f.denum-this->denum*f.num;
	fn.denum=this->denum*f.denum;
	}

	return fn;
} 
fraction& fraction :: operator*=(const fraction&f)
{
	fraction fn;
	fn.num=this->num*f.num;
	fn.denum=this->denum*f.denum;
	return fn;


}
fraction& fraction:: operator/=( fraction&f)
{
	fraction fn;
	f=f.operator*();
	fn.num=this->num*f.num;
	fn.denum=this->denum*f.denum;
	return fn;

}
bool fraction ::  operator>(const fraction&f) const
{
	if ((this->num/this->denum)>(f.num/f.denum))
		return true;
	else
		return false;



}
bool fraction :: operator<(const fraction&f) const
{
		if ((this->num/this->denum)<(f.num/f.denum))
		return true;
	else
		return false;
}
bool fraction :: operator==(const fraction&f) const
{
	if ((this->num/this->denum)==(f.num/f.denum))
		return true;
	else
		return false;

}
bool fraction :: operator!=(const fraction&f) const
{
	if ((this->num/this->denum)!=(f.num/f.denum))
		return true;
	else
		return false;

}
 ostream& operator << (ostream&os, const fraction&f)
{
	os<<f.num<<"/"<<f.denum;
	return os;
}
 istream& operator >> (istream&is, fraction&f)
 {
	 cout <<"enter numerator";
 is>>f.num;
 cout <<"enter denominator";
 is>>f.denum;
 return is;
 }