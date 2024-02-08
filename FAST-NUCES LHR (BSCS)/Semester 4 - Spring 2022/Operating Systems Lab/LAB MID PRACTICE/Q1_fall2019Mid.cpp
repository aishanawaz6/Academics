#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <sys/wait.h>
#include <semaphore.h>
#include <sys/sem.h>
using namespace std;
//short is_equal_to_current_time (unsigned short hour, unsigned short minutes)
struct task
{
char name[20];
char timeHr[3];
char timeMin[3];
void setname(char*n)
{
for(int i=0;i<strlen(n);i++)
name[i]=n[i];
}
void settimeHr(char *t)
{
int i;
for( i=0;i<strlen(t);i++)
timeHr[i]=t[i];
timeHr[i]='\0';
}
void settimeMin(char *tm)
{
int i;
for(i=0;i<strlen(tm);i++)
timeMin[i]=tm[i];
timeMin[i]='\0';
}
};

int main()
{

int fdp[2];
if(pipe(fdp)<0)
cout<<"Failed to create a pipe!"<<endl;

int fd=open("tasks.txt",O_RDONLY);
if(fd<0)
cout<<"Unable to open tasks.txt!"<<endl;

//Reading data from file.
char *c=new char [5000];
read(fd,c,sizeof(char)*5000);
//cout<<c;

// Calculating total Number of tasks (which is equal to number of lines in txt)
int totalTasks=0;
for(int i=0;i<5000;i++)
{
if(c[i]=='\n')
totalTasks++;
}
cout<<"NUMBER OF TASKS ARE: "<<totalTasks<<endl;

pid_t pid;
int j;
for(j=0;j<totalTasks;j++)
{
pid=fork();
if(pid==0)
break;
}

if(pid==0)
{
task *tc=new task[totalTasks];
close(fdp[1]);
if(read(fdp[0],&tc[j],sizeof(task))==0)
cout<<"READ FAILED!"<<endl;
close(fdp[0]);

/*
unsigned short tie=atoi(tc[j].timeHr);
unsigned short tie2=atoi(tc[j].timeMin);
cout<<"TIME: "<<tie<<":"<<tie2<<endl;
while(!is_equal_to_current_time (tie, tie2));
*/
char *argv[]={tc[j].name,NULL};
//cout<<"Task "<<tc[j].name<<" running.."<<endl;
if(execvp(tc[j].name,argv)<0)
cout<<"execvp failed!"<<endl;
}

if(pid>0)
{
task *t=new task[totalTasks];
int i=0;
while(i<totalTasks)
{
t[i].settimeHr(strtok_r(c," ",&c));
t[i].settimeMin(strtok_r(c," ",&c));
t[i].setname(strtok_r(c,"\n",&c));
i++;
}

for(int i=0;i<totalTasks;i++)
{
cout<<"Task Name: "<<t[i].name;
cout<<" Task time: "<<t[i].timeHr<<":"<<t[i].timeMin<<endl;
}
close(fdp[0]);
write(fdp[1],t,sizeof(task)*totalTasks);
close(fdp[1]);
for(int i=0;i<totalTasks;i++)
wait(NULL);
}
return 0;
}