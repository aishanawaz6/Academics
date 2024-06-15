
#include <iostream>
#include "20L-0921 Citizen.h"
using  namespace std;


int main (){






	Citizen citizen1;
	Citizen citizen2("Aisha","Nz",56,"Desigantion","a");
	citizen2.Print();
	citizen1.Print();
	citizen1.input();
	citizen1.SetName("Aisha");
	 citizen1.SetSurName("Nawaz");
 citizen1.SetCNIC(2568);
	 citizen1.SetDesigantion("job");
	 citizen1.SetAddress("Lahore");


	 citizen1.GetName();
	 citizen1.GetSurName();
 citizen1.GetCNIC();
	 citizen1.GetDesigantion();
	 citizen1.GetAddress();
	system ("pause");
	return 0;

}