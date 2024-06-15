#include <iostream>
using namespace std;

int main () {
	int w1=1,w2=1,w3=1,sum;

	cout<<"Input the sum of weights of stones: ";
	cin>>sum;

	if (sum>2) {
		while (w1+w2+w3==sum) {
w3++;
		w2++;
	
		w1++;

		}

		if(w2>=w1 && w3>=w2)		
cout<<w1<<w2<<w3;
	}






	system("pause");
	return 0;
}