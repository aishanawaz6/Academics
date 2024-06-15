#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
/*
Write a C/C++ code to demonstrate the working of named pipes i.e., mkfifio. This task creates a 
named pipe ‘mkStreamChannel’. On the writing end, the Writer sends about 580000 integers to 
the pipe. The data is not to send as a whole. Your job is to send the data in the following format.

MaxIterations = 5000
ChunkSize = 29
IntegerPerChunks=4
Interval (Microsecond)=250 
Interval to be append after each iteration.
On the reader end, now read these 580000 integers, show their count, and find the total prime
numbers in them.
*/
int main ()
{
int fd=mkfifo("mkstreamChannel",0666);

if(fd<0)
cout<<"ERROR CREATING NAMED PIPE!"<<endl;



int fdd=open("mkstreamChannel",O_WRONLY);
int arr[4];

for(int i=0;i<5000;i++)
{
for(int j=0;j<29;j++)
{
for(int l=0;l<4;l++)
{arr[l]=rand() % 10;
}
write(fdd,arr,4*sizeof(int));
sleep(0.25);
}
}


close(fdd);

return 0;
}
