//L200921 Aisha Muhammad Nawaz BSCS Section 4A1 Q1 CLIENT code LAB 09 OS 

/*Q: A client process read data from a file (passed as a command-line argument) and shares the data to
a server process (unrelated process) via shared memory and the server process read the data from
the shared memory and finds the longest palindrome from the data. (Use open, read, and write
system calls for filing). Use ftok( ) to generate a unique key.*/

#include <iostream>
#include <sys/shm.h>
#include <string>
#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

int main (int argc, char*argv[]) // Command-line arguments
{
key_t key = ftok(argv[1],2); // This will ensure same key returned for same filename and id.
int key2= shmget(key,1024,0); //Allocates a shared memory segment.
if(key2<0)
{
cout<<"ERROR"<<endl;
return 0;
}

char* ptr = (char*) shmat(key2,NULL,0); // Maps shared memory segment onto the process’s address space.

// Opening specified file
int fd=open(argv[1],O_RDONLY);
if(fd<0)
{
cout<<"ERROR OPENING FILE!"<<endl;
return 0;
}

//Writing contents of file to shared region.
read(fd,ptr,sizeof(char)*1000);

// TO detach
shmdt(ptr);

return 0;
}