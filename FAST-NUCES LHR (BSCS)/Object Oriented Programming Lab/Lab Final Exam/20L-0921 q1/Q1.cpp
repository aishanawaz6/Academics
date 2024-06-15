#include <iostream>
#include "Q1.h"
using namespace std;


	//Create all necessary functions here
	Binary:: Binary ()
	{
	number=NULL;
	length=0;
	}
	Binary::	Binary (int*n,int l)
	{
	number=new int [l];
	number=n;
	length=l;	
	}
		Binary::Binary (const Binary&b)
	{
			length=b.length;	
	number=new int [length];
for (int i=0;i<b.length;i++)
	number[i]=b.number[i];

	}
	
	Binary 	Binary:: operator ||(Binary&b)
	{
		Binary c(*this);
		for (int i=0;i<length;i++)
		{
		if ((number[i]==1) || (b.number[i]==1))
			c.number[i]=1;
		else
			c.number[i]=0;


		}
	return c;
	}
	Binary	Binary:: operator && (Binary&b)
	{
		Binary c(*this);
		for (int i=0;i<length;i++)
		{
		if ((number[i]==1) && (b.number[i]==1))
			c.number[i]=1;
		else
			c.number[i]=0;


		}
	return c;
	}
	Binary 	Binary::operator ! ()
	{
		Binary c(*this);
		for (int i=0;i<length;i++)
		{
		if (number[i]==1)
			c.number[i]=0;
		else
			c.number[i]=1;
		}
	return c;
	}
	/*Binary:: ~ Binary ()
	{
	delete []number;
	number=NULL;
	}*/

istream& operator >> (istream&in,Binary&b)
{
	cout<<"Please enter size of array: ";
		do {
		in>>b.length;
		if (b.length<1)
			cout<<"Sorry size cannot be less than or equal to zero Please enter again: ";
		}
		while(b.length<1);
cout<<"Please enter elements of array: ";
b.number=new int [b.length];
	for (int i=0;i<b.length;i++)
	{
		do {
		in>>b.number[i];
		if ((b.number[i]!=1) && (b.number[i]!=0))
			cout<<"Sorry input should be only 1 or 0! Please enter again: ";
		}
		while(b.number[i]!=1 && b.number[i]!=0);
	}
	return in;

}
ostream& operator << (ostream&out,const Binary&b)
{
		for (int i=0;i<b.length;i++)
out<<b.number[i]<<" ";
cout<<endl;
return out;
}

