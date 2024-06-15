#include <iostream>
using namespace std;

class Cents {
	int m_cent;

public:
	Cents (Cents&c)
	{
	this->m_cent=c.m_cent;
	}
	Cents (int c)
	{
	this->m_cent=c;
	}
	
	Cents operator + (const int a)
	{
		Cents c(*this);
		c.m_cent=this->m_cent+a;
		return c;
	}
	Cents operator - (const int b)
	{
		Cents c(*this);
		c.m_cent=this->m_cent-b;
		return c;
	}
	int getCents()
	{
	return this->m_cent;
	}
};


int main()
{
    Cents cents1(6);
    Cents cents2 = cents1 + 2;
    cout << "I have " << cents2.getCents() << " cents.\n";
    Cents cents3 = cents1 - 3;
    cout << "I have " << cents3.getCents() << " cents.\n";

	system ("pause");
    return 0;
}
