#include <iostream>
using namespace std;

int main () {
int julianday;

cout<<"Please enter a julian day: ";
cin>>julianday;

int day;
day=(julianday+1)%7;
cout<<"Julian day number "<<julianday<<" is a ";
switch (day) 
{
case 0:
cout<<"Sunday."<<endl;
break;
case 1:
cout<<"Monday."<<endl;
break;
case 2:
cout<<"Tuesday."<<endl;
break;
case 3:
cout<<"Wednesday."<<endl;
break;
case 4:
cout<<"Thursday."<<endl;
break;
case 5:
cout<<"Friday."<<endl;
break;
case 6:
cout<<"Saturday."<<endl;
break;
default : 
cout <<"Invalid julian day!"<<endl;
}

system("pause");
return 0;
}