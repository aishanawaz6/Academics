#include <iostream>
using namespace std;

int main () {
	int j;
	cout<<"Please enter an integer value: ";
	cin>>j;
	if (j>=0 && j%2 == 0)
		cout <<"Entered number is an positive even number\n";

	else if (j>=0 && j%2 !=0)
		cout <<"Entered number is an positive odd number\n";

		else if (j<0)
			{j=-1*j;
			cout <<j<<endl;
	if (j%2 ==0)
		cout <<"Entered Number is even\n";
	else 	if (j%2 !=0)
		cout <<"Entered Number is odd\n";
	}
	system("pause");
	return 0;
}