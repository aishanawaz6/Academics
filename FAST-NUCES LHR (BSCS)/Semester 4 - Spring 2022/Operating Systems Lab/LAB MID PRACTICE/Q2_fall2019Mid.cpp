#include <iostream>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>
#include <cstring>
using namespace std;
int size[100]; //Assuming maximum filenames can be 100
int count=0;
void* fun(void*fn)
{

char *h=(char*)fn;// Filename given by user
int fd=open(h,O_RDONLY);
{
if(fd<0)
{
cout<<"FILE NOT FOUND!"<<endl;
exit(0);
}
}
char*MapPointer=(char*)mmap(NULL,100,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);//MAP
size[count]=strlen(MapPointer); //This way returns size
count++;
return MapPointer;
}

int main(int argc,char*argv[])
{
if(argc<2) //IF NO INPUT FROM COMMAND-LINE EXIT.
{
cout<<"No input!"<<endl;
return 0;
}

pthread_t *id=new pthread_t[argc-1];

char **MapP=new char*[argc-1];//A map pointer for every filename
for(int i=0;i<argc-1;i++)
MapP[i]=new char[5000];

for(int i=0;i<argc-1;i++)
{
pthread_create(&id[i],NULL,fun,(void*)argv[i+1]);
pthread_join(id[i],(void**)&MapP[i]); //Inorder to execute in the same sequence as the filnames are given in command-line
}

cout<<"All THREADS DONE!"<<endl;
int tsize=0;
for(int i=0;i<argc-1;i++)
tsize=tsize+size[i];

int fd=open("output.txt",O_RDWR|O_APPEND|O_CREAT,0666);
char*MainMapPointer=(char*)mmap(NULL,sizeof(char)*tsize,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);//MAP

int k=0;
for(int i=0;i<argc-1;i++)
{
for(int j=0;j<strlen(MapP[i]);j++,k++)
MainMapPointer[k]=MapP[i][j];
munmap(MapP[i],size[i]);
}
cout<<MainMapPointer;

pthread_exit(0);
return 0;
}