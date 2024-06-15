#include <iostream>
#include "Math.h"
using namespace std;

int main () 
{
	Math m;
	m.print();
	Math n;
	n=++m;
n.print();
n=--m;
n.print();
m=n++;
m.print();
n=m--;
n.print();
	
	



system ("pause");
return 0;
}