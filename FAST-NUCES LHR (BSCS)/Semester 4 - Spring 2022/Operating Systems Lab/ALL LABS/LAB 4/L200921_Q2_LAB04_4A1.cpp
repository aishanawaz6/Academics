//20L-0921 AISHA MUHAMMAD NAWAZ Q2 LAB 04 OS BSCS SECTION 4A1

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <cstring>
using namespace std;

int main ()
{
cout<<"WELCOME ENTER X TO EXIT!"<<endl; ///ASSUMING USER ENTERS X INSTEAD OF CTRL+D
char com[50];
char arg[100];
char arg2[100];

cout<<"Enter Command: ";
cin.getline(com,50);
if(com[0]=='X')
exit(0);
cout<<"Enter Argument 1: ";
cin.getline(arg,100);
cout<<"Enter Argument 2: ";
cin.getline(arg2,100);

int pd=fork();
if(pd<0)
{
cout<<"Fork System Call Failed!"<<endl;
exit(1);
}

while(true)
{
if(pd>0)
{
/* Parent's Code */
wait(NULL);
cout<<"Enter command again: ";
cin.getline(com,50);
if(com[0]=='X')
exit(0);
cout<<"Enter Argument 1 again: ";
cin.getline(arg,100);
cout<<"Enter Argument 2 again: ";
cin.getline(arg2,100);
pd=fork();
}

if(pd==0)
{
/* Child's Code  */

cout<<"CHILD said your command is: "<<com<<endl;
cout<<"CHILD said your Arguments are: "<<arg<<" AND "<<arg2<<endl;
execlp(com,arg,arg2,NULL);


}

}


return 0;
}
