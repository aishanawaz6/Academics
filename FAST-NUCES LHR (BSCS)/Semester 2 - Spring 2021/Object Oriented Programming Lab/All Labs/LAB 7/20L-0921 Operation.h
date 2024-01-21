#include <iostream>
using namespace std;

class Operation  {
	int a ;
	int b;

public :
	Operation ();
	Operation (int aa, int bb);
	void seta (int a1);
	void setb(int b1);
	int geta();
	int getb();
	inline void sum();
	inline void difference();
	inline void product();                               
	inline void division();

	// Write in Comments section what are the benefits of inline function.
	// Answer : 1) Can be used to reduce overhead of function calls 2) Reduces Execution Time

};