#include <iostream>
#include<stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <cstring>
#include <sys/wait.h>
#include <sys/types.h>
#include <fstream>
using namespace std;


int main ()
{
int pd2=1;
int fd[2];
int p1=pipe(fd);
bool go=false;
int fd2[2];
int p2=pipe(fd2);
int pd=fork();


if (pd>0)
{
wait(NULL);
//Parent's Code

close (fd[1]);
int arr2[10];
read(fd[0],&arr2,sizeof(int[10]));
close (fd[0]);

cout<<"ARRAY SENT FROM CHILD IS: ";
for (int i=0;i<10;i++)
cout<<arr2[i]<<" ";

int n=0;
cout<<"Enter value of N : ";
cin>>n;

int arr3[10];
int j=10-n;
int k=0;
for (int i=9;k<n;j++,k++,i--)
{
arr3[k]=arr2[j];
}
for (int i=0;i<10-n;i++,k++)
arr3[k]=arr2[i];

cout<<"Rotated Array is as follows: ";
for (int i=0;i<10;i++)
{
cout<<arr3[i]<<" ";
}

/*if(p2<0)
{
cout<<"ERROR CREATING PIPE2!"<<endl;
exit(1);
}


//1 for write
close(fd2[0]);
write (fd2[1],&arr3,sizeof(int[10]));
close(fd2[1]);
int pd2=fork();*/

}
else
if (pd==0)
{
//Child's Code
int arr[10];
ifstream file;
file.open("integers.txt");
int s=0;
while (s<10)
{
file>>arr[s];
s++;
}
if(p1<0)
{
cout<<"ERROR CREATING PIPE!"<<endl;
exit(1);
}

//1 for write
close(fd[0]);
write (fd[1],&arr,sizeof(int[10]));
close(fd[1]);


}


if (pd2==0)
{
close (fd2[1]);
int arr4[10];
read(fd2[0],&arr4,sizeof(int[10]));
close (fd2[0]);

cout<<"Rotated Array is as follows: ";
for (int i=0;i<10;i++)
{
cout<<arr4[i]<<" ";
}
}
return 0;
}