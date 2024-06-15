#include <iostream>
#include "fraction.h"
using namespace std;

int main() {

	fraction what;
	!what;
	what.setnum(14);
	what.setdenum(5);
	!what;
	fraction why(5,2);
	!why;
	fraction when;
	when=why;
	!when;
	fraction a1(7,8);
		fraction a2;
	 a2.setnum (a1.getnum());
	  a2.setdenum (a1.getdenum());
	  !a2;

	  -a2;
	  !a2;
	  *a2;
	  !a2;

	 what= what.operator +=(why);
	 !what;
	  what= what.operator -=(why);
	  !what;
	  what= what.operator *=(why);
	 !what;
	 what= what.operator /=(why);
	 !what;
	 cout<<what.operator ==(what)<<endl;
	  cout<<what.operator >(what)<<endl;
	   cout<<what.operator <(what)<<endl;
	    cout<<what.operator !=(what)<<endl;


		cout<<a2;
		fraction a5;
		cin>>a5;
		!a5;


system ("pause");
return 0;
}