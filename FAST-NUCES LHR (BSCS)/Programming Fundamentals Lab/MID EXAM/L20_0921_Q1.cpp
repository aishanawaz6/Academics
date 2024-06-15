#include <iostream>
using namespace std;

int main () {
	char x;
	 cout<<"Please enter any character: ";
	 cin>>x;

	 if((x>='A' && x <='Z') || (x>='a' && x<='z'))
		 cout<<"It is character "<<endl;
	 else 
		 if (x>='1' && x<='9')
			 cout<<"It is number"<<endl;
		 else
			 cout<<"It is special character "<<endl;


	system("Pause");
	return 0;
}