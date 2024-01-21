#include <iostream>
using namespace std;


//Given is the data members of class Binary. You have to complete the class definition such that the provided main function runs perfectly.
class Binary
{
private:
	int * number;		//an array to sore the 1s and 0s. There should be 1s and 0s only!!!
	int length;			//length of array
public:
	//Create all necessary functions here
	Binary ();
	Binary (int*n,int l);
	Binary (const Binary&b);
	friend istream& operator >> (istream&in,Binary&b);
	friend ostream& operator << (ostream&out,const Binary&b);
	Binary operator ||(Binary&b);
	Binary operator && (Binary&b);
	Binary operator ! ();
	//~ Binary ();
};