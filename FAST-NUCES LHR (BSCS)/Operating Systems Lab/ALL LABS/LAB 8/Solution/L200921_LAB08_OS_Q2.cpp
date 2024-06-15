/*Write a Program in which the child sends 7 messages to the parent. The message could be in any 
format. Like integer, number, or alphabets. The parent's job is to receive them and write them to 
another file in reverse order*/
#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

int main()
{

int fd[2];
pipe(fd);
int arr[7]={1,2,3,4,5,6,7};
int pid=fork();

if(pid==0) //Child's Code
{
close(fd[0]);
write(fd[1],&arr,7*sizeof(int));
close(fd[1]);
}
else 
if(pid>0) //Parent's Code
{
wait(NULL);
close(fd[1]);
int arri[7];
read(fd[0],&arri,7*sizeof(int));
close(fd[0]);


int arr2[7];
for(int j=6,i=0;j>=0;j--,i++)
arr2[i]=arri[j];



int filed=open("r.txt",O_WRONLY|O_APPEND);
write(filed,arr2,7*sizeof(int));
close(filed);
}

return 0;
}
