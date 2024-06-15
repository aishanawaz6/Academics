#include <iostream>
using namespace std;

int main ()
{
float  studentdata[5][6],marks,s,co;
cout<<"Enter Number of students: ";
cin>>s;
for (int j=1;j<=s;j++) 
{
	cout<<"---------Student # "<<j<<"-------------------------"<<endl;
cout<<"Enter Number of courses"<<j<<":           ";
cin>>co;
for (int j2=1;j2<=co;j2++)
{

cout<<"                                                 --- Course # "<<j2<<"---"<<endl;
cout<<"                                                 - Quiz # 1: ";
cin>>studentdata[0][0];
cout<<"                                                 - Quiz # 2: ";
cin>>studentdata[0][1];
cout<<"                                                 - Assignment # 1: ";
cin>>studentdata[0][2];
cout<<"                                                 - Assignment # 2: ";
cin>>studentdata[0][3];
cout<<"                                                 - Midterm: ";
cin>>studentdata[0][4];
cout<<"                                                 - Final: ";
cin>>studentdata[0][5];
cout<<"                                                 --> Total: ";
marks=0.2*(studentdata[0][0]+studentdata[0][1]+studentdata[0][2]+studentdata[0][3])+0.3*studentdata[0][4]+0.5*studentdata[0][5];
cout<<marks<<endl;
cout<<"                                                 --> Grade:  ";
    if (marks>80.0)
    cout<<"A";
 else
	if (marks>70)
	cout<<"B";
 else
   if (marks>60)
   cout<<"C";
 else
	 if (marks>50)
      cout<<"D";
 else
	cout<<"F";

cout<<endl;
}
}
system ("pause");
return 0;
}