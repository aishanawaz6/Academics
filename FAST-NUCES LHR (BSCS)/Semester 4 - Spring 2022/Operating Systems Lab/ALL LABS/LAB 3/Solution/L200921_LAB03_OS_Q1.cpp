#include <iostream>
#include <string>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main ()
{
int id=fork();
if(id>0)
{
wait(NULL);
}
else
if(id==0)
{
cout<<"Process 1 Process ID: "<<getppid()<<endl;
cout<<"Process 2 Process ID: "<<getpid()<<endl;
const char *path={"/bin/ls"};
char *const argv[]={"ls","-l","-t","/home/aisha/Desktop",NULL};
char *const envp[]={"-c",NULL};

execve (path,argv,envp);
}

return 0;
}
