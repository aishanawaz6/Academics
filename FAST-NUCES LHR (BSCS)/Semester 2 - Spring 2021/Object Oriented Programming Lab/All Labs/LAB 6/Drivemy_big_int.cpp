#include <iostream>
#include "my_big_int.h"
using namespace std;
int main() {

	int u[4]= { 9,8,7,0 };
	const int* p = u;
	int s = 4;
	BiggerInt b1(p,s);
	BiggerInt b2(b1);
	BiggerInt b3;
	const BiggerInt c1;
	b3.assign(c1);
	BiggerInt b4;
	b4.assign(p, s);
	 BiggerInt c4(p,s);
	b4.append(c4);
	


	system("pause");
	return 0;
}