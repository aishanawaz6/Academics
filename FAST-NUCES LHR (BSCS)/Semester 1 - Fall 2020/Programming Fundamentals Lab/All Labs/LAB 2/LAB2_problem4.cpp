#include <iostream>;
using namespace std;

int main() {
	int sub1,sub2,sub3,sub4,sub5;
	cout<< "please enter marks of subject 1=";
	cin>>sub1;
	cout <<  "please enter marks of subject 2=";
	cin>>sub2;
cout <<  "please enter marks of subject 3=";
	cin>>sub3;
	cout <<  "please enter marks of subject 4=";
	cin>>sub4;
cout <<  "please enter marks of subject 5=";
	cin>>sub5;
	cout << "percentage of total marks is=" <<((sub1+sub2+sub3+sub4+sub5)/500)*100;
system("pause");
	return 0;
}