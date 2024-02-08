#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

int main ()
{


int pd=fork();

if (pd==0)
{
//Child's Code
 int fd=open("dsfile.txt",O_WRONLY | O_APPEND);
cout<<"Child's Descriptor: "<<fd<<endl;
int fd1=open("dsfile.txt",O_WRONLY | O_APPEND);
cout<<"Child's Descriptor: "<<fd1<<endl;

//cout<<"Child's New Descriptor: "<<nfd<<endl;

}
if (pd>0)
{
wait(NULL);
// Parent's Code
int fd2=open("dsfile.txt",O_WRONLY | O_APPEND);
cout<<"Parent's Descriptor: "<<fd2<<endl;


}

char *arr[]={NULL};
execvp("./k.out",arr);


return 0;
}
