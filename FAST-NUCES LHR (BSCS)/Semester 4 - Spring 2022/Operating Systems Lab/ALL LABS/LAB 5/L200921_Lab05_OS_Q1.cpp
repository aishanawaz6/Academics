#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
using namespace std;

int main ()
{
int file_desc=open("dup.txt",O_WRONLY|O_APPEND);
if(file_desc<0)
cout<<"Error opening the file!";
int pid=fork();
if(pid==0)
{// Child's Code


int copy_desc=dup(file_desc);
write(copy_desc,"This will be written to file by child!!",39);


}
else 
if(pid>0)
{
// Parent's code
wait(NULL);
int copy_desc=dup(file_desc);
write(copy_desc,"This will be written to file by parent!!",40);
}




return 0;
}
