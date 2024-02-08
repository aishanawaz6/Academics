#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <cstring>
using namespace std;

int main ()
{
 cout << getpid() <<  endl;
 
 while (1) {}

return 0;
}
