//20L-0921 AISHA MUHAMMAD NAWAZ Q1 LAB 04 OS BSCS SECTION 4A1

#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sys/types.h>
using namespace std;


int main ()
{
int pipefd[2];
int pipefd2[2];
int r=pipe(pipefd);
int r2=pipe(pipefd2);
int pd=fork();

if(pd<0)
{
cout<<"Fork System Call Failed!"<<endl;
exit(1);
} 


if(pd>0)
{
/* Parent's Code */
cout<<"Parent!"<<endl;

ifstream file;
file.open("file.txt");
if(file.is_open())
{
cout<<"Successfully opened file!"<<endl;
//Initializing array that will save data from file.
char data[100];
int i=0;
while(file) //Reading  data from file
{
file>>data[i];
i++;
}
file.close();

data[i]='\0';
if(r<0)
{
cout<<"Pipe not made."<<endl;
return 0;
}
close(pipefd[0]);
write(pipefd[1],&data,strlen(data)+1); //strlen(data)+1 so count of null is also added
close(pipefd[1]);

//Reading modified data now.
char datamod2[100];
close(pipefd2[1]);
read(pipefd2[0],&datamod2,100);
close(pipefd2[0]);

//Writing modified data to updated.txt
ofstream outfile;
outfile.open("Updated.txt");
if(outfile.is_open())
{
for(int i=0;i<strlen(datamod2)-1;i++)
outfile<<datamod2[i];

outfile.close();
}
else
cout<<"Outfile not opened!"<<endl;
}
else
{
cout<<"Unable to open file!"<<endl;
return 0;
}
}

if (pd==0)
{
/* Child's Code */

cout<<endl<<"CHILD!"<<endl;
close(pipefd[1]);

char data2[100];
char datamod[100];
int k=0;

read(pipefd[0],&data2,100);
close(pipefd[0]);

for(int j=0;data2[j]!='\0';j++) //saving data read from pipe to another array
{
if (data2[j]!='&' && data2[j]!='@' && data2[j]!='#' && data2[j]!='%'&& data2[j]!='*'&& data2[j]!='?'&& data2[j]!='&'&& data2[j]!='$' && data2[j]!='"' && data2[j]!='~') 
{
datamod[k]=data2[j];
k++;
}
}
datamod[k]='\0';

if(r2<0)
{
cout<<"Pipe2 not created!"<<endl;;
exit(1);
}

close(pipefd2[0]);
write(pipefd2[1],&datamod,strlen(datamod)+1);
close(pipefd2[1]);

exit(0);
}


return 0;
}


