#include <iostream>
using namespace std;

int main () {
int accountnum,minbal,curbal;
char type;
cout<<"Please enter account number: ";
cin>>accountnum;
cout<<"Please enter account type: ";
cin>>type;
cout<<"Please enter minimum balance account should maintain: ";
cin>>minbal;
cout<<"Please enter the current balance: ";
cin>>curbal;

cout<<"Account Number: "<<accountnum<<" Account Type: "<<type<<" Minimum Balance: "<<minbal<<" Current Balance: "<<curbal<<endl;


system("pause");
return 0;
}