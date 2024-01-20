#include <iostream>
using namespace std;

float main () {
	float s,gs;
	cout<< "Please enter amount of basic salary: ";
	cin>> s;
	if (s<=10000)
		{gs = s*0.2+s*0.8+s;
	cout << "Gross salary = "<<gs<<endl;
}
	else if (s<=20000)
	{gs = s*0.25+s*0.9+s;
	cout << "Gross salary = "<<gs<<endl;
	}

	else if (s>20000)
	{gs = s*0.30+s*0.95+s;
	cout << "Gross salary = "<<gs<<endl;
	}
	system("pause");
	return 0;

}