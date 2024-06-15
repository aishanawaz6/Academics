//Aisha Muhammad Nawaz 20L-0921 BSCS 4A1 OS ASSIGNMENT 1 SPRING 2022
#include <iostream>
#include <cstring>
#include <sys/wait.h>
#include <unistd.h>
using namespace std;       


int main ()
{         cout<<"---WELCOME TO THIS VERSION OF SHELL.---"<<endl;
          cout<<"---PLEASE ENTER ALL COMMANDS IN CORRECT FORMAT---"<<endl;
          
          cout<<endl<<"Enter Command: ";
          //User command will be stored in a character array of size max 500
          char*com=new char[500]; 
          cin.getline(com,500);  //The user types a command for the first time.
          
         char*file=strtok_r(com," ",&com); // Peforms Tokenization for the first time
         //It is assumed file/command will be before first " " (space) and its arguments after first " ".
         char* argv[]={com,NULL}; 
 
  
  
 int id=fork(); //Then creates a child process

while(true)
{
if(id>0) // Parent's Code
{
wait(NULL); //Parent shall wait for the child to finish execution.


cout<<endl<<"Enter Command Again: "; //Once again user enters command
char *com=new char[500];
cin.getline(com,500);

if(strcmp(com,"exit")==0) //Will exit if command given by user is exit.
                          {
                           cout<<"You have decided to exit."<<endl;
                          exit(0);     
                          }      
  //Tokenization here again                    
  file=strtok_r(com," ",&com); 
  argv[0]=com; 

id=fork();
}
else
     if(id==0) //Child's Code
{
cout<<"Your command was: "<<file<<endl;
if(strlen(argv[0])) //If any arguments passed
cout<<"The Arguments passed were: "<<argv[0]<<endl;

cout<<"RESULT:"<<endl;
execvp(file,argv); //The child will use the execvp system call to execute the command.
}

}
return 0;
}