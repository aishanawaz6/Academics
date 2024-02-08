#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;


int main (int args,char *argv[])
{
int n=atoi(argv[1]); // To convert to int
int p =0;
p = fork();
wait (NULL);
for (int i=0;i<n;i++)
{

if(p==0)
{
cout<<"Child Process Created!"<<endl;
cout<<"Parent ID: "<<getppid()<<" Child ID: "<<getpid()<<endl;
p = fork();
wait (NULL);
}
else
  if (p<0)
cout<<"Error in creating child process!"<<endl;
}



return 0;
}
