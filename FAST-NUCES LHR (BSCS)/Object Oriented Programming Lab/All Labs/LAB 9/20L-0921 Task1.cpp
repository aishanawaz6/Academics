#include <iostream>
using namespace std;

class Marks {
	
	int subject[3];
public:
	Marks ()
	{
	this->subject[0]=0;
	this->subject[1]=0;
	this->subject[2]=0;
	}
	Marks (int a, int b, int c)
	{
	this->subject[0]=a;
	this->subject[1]=b;
	this->subject[2]=c;
	}
	int & operator  [] (const int i) 
	{
	if (i>=0 && i<3)
		return this->subject[i];
	}








};









int main()
{
    Marks saif(77,88,99);
    //0 represent marks of Data Structure
    //1 represent marks of OOP
    //2 represent marks of Programming Fundamental
    cout<<"Saif Your Obtained Marks in Programming Fundamental is: "<<saif[2]<<endl<<endl;
    cout<<"Saif Your Obtained Marks in OOP is: "<<saif[1]<<endl<<endl;
    cout<<"Saif Your Obtained Marks in Data Structure is: "<<saif[0]<<endl<<endl;

	system ("pause");
    return 0;
}
