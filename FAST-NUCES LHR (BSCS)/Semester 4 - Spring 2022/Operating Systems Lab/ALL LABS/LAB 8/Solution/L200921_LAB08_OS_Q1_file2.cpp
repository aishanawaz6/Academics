#include <iostream>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
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

bool isprime(int n)
{
int p=1;
if(n==0||n==1)
return false;

for(int i=2;i<n;i++)
{
if(n%i==0)
p++;
}

if(p>1)
return false;
else
return true;
}



int main ()
{
int count=0;
int prime=0;
int arr[4];
int fd=open("mkstreamChannel",O_RDONLY);
for(int i=0;i<5000;i++)
{
for(int j=0;j<29;j++)
{
read(fd,&arr,sizeof(int)*4);
for(int k=0;k<4;k++){
if(isprime(arr[k]))
prime++;
count++;
}
}

}

cout<<"TOTAL COUNT OF NUMBERS: "<<count<<endl;
cout<<"TOTAL PRIME NUMBERS: "<<prime<<endl;
close(fd);




return 0;
}
