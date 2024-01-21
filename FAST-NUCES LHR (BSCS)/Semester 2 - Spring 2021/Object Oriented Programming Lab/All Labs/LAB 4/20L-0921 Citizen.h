#include <iostream>
#include <string>
using namespace std;


class Citizen {
private :
string Name;
string SurName;
int CNIC;
string Designation;
string Address;

public:
	Citizen ();
	Citizen (string n,string sn,int c,string d,string a);
	void SetName(string n);
	void SetSurName(string sn);
	void SetCNIC(int c);
	void SetDesigantion(string d);
	void SetAddress(string a);

	void GetName();
	void GetSurName();
	void GetCNIC();
	void GetDesigantion();
	void GetAddress();

	void input ();
	void Print();


};