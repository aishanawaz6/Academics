#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;

int main ()
{
int fd[2];
pipe(fd);
int pid = fork();
if(pid>0)
{
//Parent's code
int arr[5]={1,2,3,4,5};
close(fd[0]);
write(fd[1],&arr,sizeof(int[5]));
close(fd[1]);
}
if(pid==0)
{
//Child's code
int arr2[5];
close(fd[1]);
read(fd[0],&arr2,sizeof(int[5]));
int min=arr2[0];
int max=arr2[0];
for(int i=0;i<5;i++)
{
if(arr2[i]<min)
min=arr2[i];
if(arr2[i]>max)
max=arr2[i];

}
cout<<"Min : "<<min<<endl;
cout<<"Max: "<<max<<endl;
cout<<"Avg: "<<(min+max)/2<<endl;
}

return 0;
}