#include <iostream>
using namespace std;

float main() {
float base, hypotenuse;
cout << "Please enter base of triangle :";
cin>> base;
cout << "Please enter hypotenuse of triangle:";
cin>> hypotenuse;
cout <<"Area of triangle is:"<<0.5*base*sqrt((hypotenuse*hypotenuse)-(base*base));
system ("pause");

	return 0;
}