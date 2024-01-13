#include <iostream>
using namespace std;

class ComplexNumber
{
private:
float real;
float img;
public:
	ComplexNumber()
	{
		cout<<"Default constructor called!"<<endl;
	this->real=1;
	this->img=1;
	}
ComplexNumber(float r, float a )
{
	cout<<"Parameterized constructor called!"<<endl;
this->real=r;
this->img=a;
}
ComplexNumber(const ComplexNumber & cn)
{
	cout<<"Copy constructor called!"<<endl;
	this->real=cn.real;
	this->img=cn.img;
	
}
friend istream & operator>>(istream & in, ComplexNumber & cn)
{

// cin >> complexNo1 >> complexNo2;
	cout<<"Please enter real part of complex number: ";
	in>>cn.real;
	cout<<"Please enter imaginary part of complex number: ";
	in>>cn.img;

	return in;

}
friend ostream & operator<<(ostream & out, const ComplexNumber & cn)
{
//cout << complexNo1 << complexNo2; //3+4i, 5+10i
	if (cn.img<0)
	{
		out<<cn.real<<cn.img<<"i"<<endl;
	}
	else
		out<<cn.real<<"+"<<cn.img<<"i"<<endl;
	
	return out;
}
ComplexNumber & operator++(int)
{
//post increment operator. complexNo++;
	 ComplexNumber c(*this);
	 c.real=this->real++;
	 c.img=this->img++;
	 cout<<"Successfully Post incremented"<<endl;
	 return c;

}
ComplexNumber & operator++()
{
//pre increment operator. ++complexNo;
	ComplexNumber c(*this);
	c.real=++this->real;
	c.img=++this->img;
	cout<<"Successfully Pre incremented"<<endl;
	return c;
}
bool operator!=(const ComplexNumber & cn)
{
// cout<< (complexNo1 != complexNo2)
	if (this->real!=cn.real || this->img!=cn.img)
	return true;
	else
		return false;


}
friend ComplexNumber operator+(const float f, ComplexNumber & cn)
{
// 2.5+complexNo; will add 2.5 to all members of complexNo.
	cn.real=cn.real+f;
	cn.img=cn.img+f;
	cout<<"Successfully Added "<<f<<endl;
	return cn;

}
};

int main () {

       ComplexNumber c;
	   cout<<"Complex Number 1 created with default values: "<<c;
	   ComplexNumber c2(3,-9);
	   cout<<"Complex Number 2 created with parameterized constructor(3,-9): "<<c2;
	   ComplexNumber c3(c2);
	   cout<<"Complex Number 3 made with copy constructor, copying c2 values: "<<c3;
	  ComplexNumber c4,c5;
	  cout<<"Now taking input for 2 complex numbers, c4 & c5......"<<endl;
	  cin>>c4>>c5;
	  cout<<"Displaying both the complex numbers....."<<endl;
cout<<"c4: "<<c4<<"c5: "<<c5;

c5=c4++;
cout<<"After c5=c4++ : "<<endl;
cout<<"c4: "<<c4<<"c5: "<<c5;
c5=++c4;
cout<<"After c5=++c4 : "<<endl;
cout<<"c4: "<<c4<<"c5: "<<c5;


int u=c4!=c5;
cout<<"Checking if c4 != c5 : "<<u<<endl;

ComplexNumber c6;
cout<<"Before adding 2.8 to new complex number: " <<c6;
2.8+c6;
cout<<"After adding 2.8 to new complex number: " <<c6;

system ("pause");
return 0;
}