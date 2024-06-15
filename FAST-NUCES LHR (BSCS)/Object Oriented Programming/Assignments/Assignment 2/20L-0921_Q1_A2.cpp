#include <iostream>
using namespace std;
class ComplexNumber
{
private:
	double real;
	double imag;
public:
	 ComplexNumber();
	ComplexNumber(double r,double i);
	void SetReal(double r);
	void SetImag(double i);
	ComplexNumber Add(ComplexNumber & cn);
	//performs addition of two complex numbers

	bool isEqual (ComplexNumber & cn);
	/*compares two complex numbers if they are equal. 
	Two complex numbers are equal if there corresponding real and imaginary
	parts are equal*/

	void print ();
};
ComplexNumber :: ComplexNumber ()
{
		real=0.0;
	    imag=0.0;
}
ComplexNumber :: ComplexNumber (double r,double i) 
{
		real=r;
	    imag=i;
}
void ComplexNumber:: SetReal (double r)
{
	real=r;
}
void ComplexNumber:: SetImag (double i)
{
	imag=i;
}
ComplexNumber ComplexNumber:: Add (ComplexNumber & cn)
{
	ComplexNumber ans;
	ans.SetReal(real+cn.real);
	ans.SetImag(imag+cn.imag);
	return ans;
}
bool ComplexNumber :: isEqual (ComplexNumber & cn)
{
	if (real==cn.real && imag==cn.imag)
		return true;
	else
	   return false;
}
void ComplexNumber :: print ()
{
	cout<<real<<" + "<<imag<<"i"<<endl;
}

int main () 
{
	ComplexNumber c1;
	c1.SetReal(5.0);
	c1.SetImag(10.0);

	ComplexNumber c2(2.0,4.0);
	ComplexNumber c3;
	if (!c1.isEqual(c2))
	{
		c3=c1.Add(c2);
	}
	else
		c3.print();


	c1.print();
	c2.print ();
	c3.print();

	system("pause");
	return 0;
}