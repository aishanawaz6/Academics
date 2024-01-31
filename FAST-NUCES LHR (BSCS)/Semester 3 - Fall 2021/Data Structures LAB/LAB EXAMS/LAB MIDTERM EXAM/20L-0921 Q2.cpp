#include<iostream>
#include <string>
using namespace std;

class stack
{
	string*str;
	int size;
	int count;
public:
	stack()
	{
	str=nullptr;
	size=0;
	count=0;
	
	}
	stack(int s)
	{
	str=new string[s];
	size=s;
	count=0;
	}
	int isFull()
	{
		if(count==size)
			return 1;
		else
			return 0;	
	}
	int isEmpty()
	{
	if (count==0)
		return 1;
	else
		return 0;
	
	}
	void reSize()
	{
		cout<<"Resize Function Called"<<endl;
		string*temp;
		temp=new string[size*2];
		for(int i=0;i<size;i++)
		{
		temp[i]=str[i];
		}
		str=temp;
	size=size*2;
	}
	void push(string s)
	{
	if(isFull()==1)
	{
	reSize();
	}
	str[count]=s;
		count++;
	}
	string pop()
	{
	if(isEmpty()==1)
	{
		cout<<"Stack Empty!"<<endl;
		return "-1";
	}
	count--;
	cout<<str[count]<<endl;
	return str[count];
	
	}


int getCount()
{
return count;
}
int getSize()
{
return size;
}


};




int main ()
{

	stack s(4);
	s.push("1180AF");
s.push("1230CE");
s.push("1044AD");
s.push("9020BD");

cout<<s.pop ()<<endl; //remove the element from stack and display the return address on console
s.push("1166");  
s.push("1177"); 
cout<<s.getCount()<<endl; //this function should return the count of elements in the stack
cout<<s.getSize()<<endl; //this function should return the size of array.
//remove all the elements from the stack by calling pop function and display the return address on console.*/
int i=0;
s.getCount();
while(s.getCount())
{
	s.pop ();
	i++;
}
s.pop();
	

system("pause");
return 0;
}