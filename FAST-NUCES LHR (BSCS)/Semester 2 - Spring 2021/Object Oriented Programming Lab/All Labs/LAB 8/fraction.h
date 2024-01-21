#include <iostream>
using namespace std;


class fraction
{
int num, denum;
public:
fraction(); //Constructor
fraction (int n,int d); // Overloaded Constructor
fraction  (fraction&f); // Copy Constructor
//~fraction();//destructor
void setnum(int n );
void setdenum(int d);
int getnum ();
int getdenum();

void operator!(void) const; // print the fraction
fraction operator-(void); // negative of fraction
fraction operator*(void); // reciprocal of fraction
//Fraction’s Arithematic Operators
fraction& operator+=(const fraction&f); //frac1 +=frac2
fraction& operator-=(const fraction&f); //frac1 -=frac2
fraction& operator*=(const fraction&f); //frac1 *=frac2
fraction& operator/=(fraction&f); //frac1 /=frac2
// Fraction’s Relational Operators.
bool operator>(const fraction&f) const;
bool operator<(const fraction&f) const;
bool operator==(const fraction&f) const;
bool operator!=(const fraction&f) const;
friend ostream& operator << (ostream&os, const fraction&f);
friend  istream& operator >> (istream&is,  fraction&f);
};