#include <iostream>
using namespace std;
int main();
void addfractions (int ar1[]) {
	int d,n;
	if (ar1[1]==ar1[3])
		{n=( ar1[0]+ar1[2] );
			cout<<"Numerator of result= "<<n<<endl;
			d=ar1[1];
	cout<<"Denominator of result= "<<d<<endl; }
	else
	{	n=( ar1[0]*ar1[3] +ar1[1]*ar1[2]);
		cout<<"Numerator of result= "<<n<<endl;
	d=ar1[1]*ar1[3];
	cout<<"Denominator of result= "<<d<<endl; }

}
void subtractfractions (int ar1[]) {
	int d,n;
	if (ar1[1]==ar1[3])
		{n=( ar1[0]-ar1[2] );
			cout<<"Numerator of result= "<<n<<endl;
			d=ar1[1];
	cout<<"Denominator of result= "<<d<<endl; }
	else
	{	n=( ar1[0]*ar1[3] - ar1[1]*ar1[2]);
		cout<<"Numerator of result= "<<n<<endl;
	d=ar1[1]*ar1[3];
	cout<<"Denominator of result= "<<d<<endl; }

}

void multiplyfractions (int ar1[]) {
	int d,n;
	{	n=( ar1[0]*ar1[2] );
		cout<<"Numerator of result= "<<n<<endl;
	d=ar1[1]*ar1[3];
	cout<<"Denominator of result= "<<d<<endl; }

}

void dividefractions (int ar1[]) {
	int d,n;
	{	n=( ar1[0]*ar1[3] );
		cout<<"Numerator of result= "<<n<<endl;
	d=ar1[1]*ar1[2];
	cout<<"Denominator of result= "<<d<<endl; }

}


int main () {
	int arr1[4],i;    
	char opp;
	cout<<"Enter + to perform addition"<<endl;
	cout<<"Enter - to perform subtraction"<<endl;
	cout<<"Enter * to perform multiplication"<<endl;
	cout<<"Enter / to perform division"<<endl;
	cin>>opp;
	cout<<"Enter the numerator and denominator of two fractions(denominators should not be zero) : "<<endl;
	for (i=0;i<4;i++) {
	cin>>arr1[i];
	}

	if (opp=='+')
		addfractions ( arr1 );
	else
		if (opp=='-')
			subtractfractions (arr1 );
		else
			if (opp=='*')
				multiplyfractions (arr1);
			else
				if (opp=='/')
					dividefractions(arr1);
				else
					cout<<"Invalid operator!"<<endl;
	system("pause");
	return 0;

}