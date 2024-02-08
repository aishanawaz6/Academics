//L200921 Aisha Muhammad Nawaz BSCS Section 4A1 Q1 SERVER code LAB 09 OS 

/*Q: A client process read data from a file (passed as a command-line argument) and shares the data to
a server process (unrelated process) via shared memory and the server process read the data from
the shared memory and finds the longest palindrome from the data. (Use open, read, and write
system calls for filing). Use ftok( ) to generate a unique key.*/

#include <iostream>
#include <sys/shm.h>
#include <string>
using namespace std;
int findlongest_P(string str);

int main (int argc, char *argv[]) // Command-line arguments
{
// Creating a shared region.
key_t key = ftok(argv[1],2); // This will ensure same key returned for same filename and id
if (key<0)
cout<<"ERROR"<<endl;

int key2=shmget(key,1024,IPC_CREAT |0666); //Allocates a shared memory segment.
if(key2<0)
{
cout<<"ERROR!"<<endl;
return 0;
}

char* ptr = (char*) shmat(key2,NULL,0); // Maps shared memory segment onto the process’s address space.

cout<<"shm created with id= "<<key2<<endl;
ptr[0]='\0';

cout<<"Waiting for the client process to send data..."<<endl;
while (ptr[0]=='\0'); //busy wait

cout<<"LENGTH IS: "<<findlongest_P(ptr)<<endl;


shmdt(ptr); //TO Detach
shmctl(key2, IPC_RMID, NULL); //mark the shared region for deletion

return 0;
}

int findlongest_P(string str)
{
    int n = str.size(); // calculating size of string
    if (n < 2)
        return n; // if string is empty then size will be 0.
                  // if n==1 then, answer will be 1(single
                  // character will always palindrome)
 
    int maxLength = 1,start=0;
    int low, high;
    for (int i = 0; i < n; i++) {
        low = i - 1;
        high = i + 1;
        while ( high < n && str[high] == str[i]) //increment 'high'                                  
            high++;
       
        while ( low >= 0 && str[low] == str[i]) // decrement 'low'                   
            low--;
       
        while (low >= 0 && high < n && str[low] == str[high]){
              low--;
            high++;
        }
 
        int length = high - low - 1;
        if (maxLength < length) {
            maxLength = length;
              start=low+1;
        }
    }
     
      cout<<"Longest palindrome substring is: ";
      cout<<str.substr(start,maxLength);
    return maxLength;
}