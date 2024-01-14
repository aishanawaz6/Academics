//20L-0921 AISHA MUHAMMAD NAWAZ BSCS SECTION 4A1 OS ASSIGNMENT # 2 
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
using namespace std;

int getposition (const char*arr,int size,const char *ch)
{
int r=-1;
int i=0;
bool present=false;
for (i=0;i<size && !present;i++)
{
present=(arr[i]==ch[0]);
if(!present)
present=(arr[i]==ch[1]);
if(!present)
present=(arr[i]==ch[2]);


}
if(present)
r=--i;

return r;
}

int main ()
{

 cout<<"~~~ WELCOME TO A NEW VERSION OF SHELL. ~~~"<<endl;
 cout<<"~~~ PLEASE ENTER ALL COMMANDS IN CORRECT FORMAT ~~~"<<endl;
int fd[2];
int fd2[2];
bool moretoit=false;
char *more=NULL;
bool old=false;
int p1,p2;
while(true)
{
p1=pipe(fd);
p2=pipe(fd2);
if(p1<0||p2<0)
{cout<<"ERROR CREATING PIPES"<<endl;
return 0;
}
bool inpOut=false; //Keeps track of input redirection.
if(more)
{
if(strlen(more)>1)
moretoit=true;
else
{moretoit=false;
old=false;
}
}

char *com=new char[500];
if(!moretoit)
{
old=false;
cout<<endl<<endl<<"--> ENTER COMMAND: ";
cin.getline(com,500);
}
else
{
com=more;
old=true;
}


if(strcmp(com,"exit")==0) //Will exit if command given by user is exit.
                          {
                           cout<<"You have decided to exit."<<endl;
                           break;     
                          } 
bool pipee=false;
for(int i=0;com[i]!='\0';i++) // Checks if pipe present in command.
{
if (com[i]=='|')
pipee=true;
}

char *bp;  
char *ap=NULL;
if(pipee) // Tokenizes command into two. One before pipe one after pipe.
{

bp=strtok_r(com,"|",&com); 
ap=strtok_r(com,"|",&com);
if(strlen(com)>1)
{
moretoit=true;
}
more=com;
}
else
bp=com;


int pid=fork();

if(pid==0)   //Child's code
                             {
                             if(pipee)
cout<<"Command before pipe: "<<bp<<endl;

// To figure out input or output redirection.
int tellwhich=-1; //-1 for none, 0 for < output , 1 for input >
                                 for(int i=0;bp[i]!='\0';i++)
                             {
if (bp[i]=='<')
tellwhich=0;

if (bp[i]=='>')
tellwhich=1;
                             }
                           

char*filename=new char[500];
if(tellwhich!=-1) //Input or output redirection required
{
inpOut=true;
char *dm=new char[2];
dm[0]='>';
dm[1]='<';

int ps=getposition(bp,strlen(bp),dm);
int j=0;
bool f=false;
for(int i=0;bp[i]!='\0';i++) // Seperating filename from full command.
{
if(i>ps && bp[i]!=' ') //bp[i]!=' ' to avoid adding space in filename.
{
filename[j]=bp[i];
j++;
}
}
bp[ps]='\0';
}

                      
  // TOKENIZING OF COMMAND.                           
const char delimiters[]="<>| ";                   
char*argv[500];


        argv[0]=strtok(bp,delimiters);
        int i=0;
        while(argv[i]!=NULL ){
        argv[++i]=strtok(NULL,delimiters); 
        }
        
         
        
         
     if(argv[0])         
cout<<"Command : "<<argv[0]<<endl;
if(argv[1])
{
cout<<"ARGUMENTS: ";
for(int k=1;argv[k];k++)
cout<<argv[k]<<" ";
cout<<endl;
}

if(inpOut)
{
if(tellwhich==0) // output redirection
{
int filedis=open(filename,O_RDONLY);

if(filedis<0)
{
cout<<"ERROR OPENING FILE!"<<endl;
continue;
}else
{
cout<<"Output redirection successful. Filename: "<<filename<<endl;
cout<<"~~~~~~~~~~~~~~~~~ RESULT: "<<endl<<endl;
dup2(filedis,0);
close(filedis);

}
}
if(tellwhich==1)
{
int filedis=open(filename,O_WRONLY);
if(filedis<0)
{
cout<<"ERROR FINDING FILE!"<<endl;
continue;
}else{
cout<<"~~~~~~~~~~~~~~~~~ RESULT: "<<endl<<endl;
cout<<"Input redirection successful. Filename: "<<filename<<endl;
dup2(filedis,1);
close(filedis);
}
}
}
else
if(!pipee)
cout<<"~~~~~~~~~~~~~~~~~ RESULT: "<<endl<<endl;

if(old) // old command running take input from from pipe 2
{
cout<<"taking from pipe 2"<<endl;
dup2(fd2[0],0);
}

 if(pipee) // If pipe present input redirection to pipe.
{  
dup2(fd[1],1);
}


if(execvp(argv[0],argv)<0)
cout<<"COMMAND FAILED!"<<endl;
}

if(pid>0)
wait(NULL);
if(pid>0)
{
wait(NULL);
if(pipee)
{
int pid2=fork();
if(pid2==0)
{
if(strlen(ap)>1)
cout<<"Command after pipe: "<<ap<<endl;
else
{
cout<<"No command after pipe."<<endl;
exit(0);
}
int tellwhich=-1; //-1 for none, 0 for < output , 1 for input >
for(int i=0;ap[i]!='\0';i++)
{
if (ap[i]=='<')
tellwhich=0;

if (ap[i]=='>')
tellwhich=1;
}

char*filename=new char[500];
if(tellwhich!=-1) //Input or output redirection required
{
inpOut=true;
char *dm=new char[2];
dm[0]='>';
dm[1]='<';

int ps=getposition(ap,strlen(ap),dm);
int j=0;
bool f=false;
for(int i=0;ap[i]!='\0';i++) // Seperating filename from full command.
{
if(i>ps && ap[i]!=' ') //bp[i]!=' ' to avoid adding space in filename.
{
filename[j]=ap[i];
j++;
}
}
ap[ps]='\0';
}

// TOKENIZING OF COMMAND.                           
const char delimiters[]="<>| ";                   
char*argv[500];


        argv[0]=strtok(ap,delimiters);
        int i=0;
        while(argv[i]!=NULL )
        argv[++i]=strtok(NULL,delimiters); 
       
        
//------------------------TILL HERE TOKENIZING.
        if(argv[0])
cout<<"Command : "<<argv[0]<<endl;
if(argv[1])
{
cout<<"ARGUMENTS: ";
for(int k=1;argv[k];k++)
cout<<argv[k]<<" ";
cout<<endl;
}

if(inpOut)
{
if(tellwhich==0) // output redirection
{
int filedis=open(filename,O_RDONLY);

if(filedis<0)
cout<<"ERROR OPENING FILE!"<<endl;
else
{
cout<<"Output redirection successful. Filename: "<<filename<<endl;
cout<<"~~~~~~~~~~~~~~~~~ RESULT: "<<endl<<endl;
dup2(filedis,0);
close(filedis);

}
}
if(tellwhich==1)
{
int filedis=open(filename,O_WRONLY);
if(filedis<0)
cout<<"ERROR FINDING FILE!"<<endl;
else{
cout<<"~~~~~~~~~~~~~~~~~ RESULT: "<<endl<<endl;
cout<<"Input redirection successful. Filename: "<<filename<<endl;
dup2(filedis,1);
close(filedis);
}
}
}
else
cout<<"~~~~~~~~~~~~~~~~~ RESULT: "<<endl<<endl;

if(moretoit) //if further present pipes.
{
cout<<"more to it!"<<endl;
dup2(fd2[1],1);
close(fd2[1]);
close(fd2[0]);
}

dup2(fd[0],0);
close(fd[0]);
close(fd[1]);


if(execvp(argv[0],argv)<0)
cout<<"COMMAND FAILED!"<<endl;
}

close(fd[0]);
close(fd[1]);


if(pid2>0)
wait(NULL);


}

}
}
close(fd[0]);
close(fd[1]);
close(fd2[0]);
close(fd2[1]);
return 0;
}