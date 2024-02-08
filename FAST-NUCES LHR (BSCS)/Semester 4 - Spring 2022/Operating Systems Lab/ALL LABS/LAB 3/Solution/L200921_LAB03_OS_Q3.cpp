#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
int main ()
{
int id=fork();
if (id>0)//For parent
{
wait(NULL);
execlp("touch","touch","/home/aisha/Desktop/OS_LABS/Lab03/20L-0921/20L-0921",NULL);
}
else
if(id==0) //For child
{
execlp("/bin/mkdir", "mkdir", "20L-0921",NULL);
}
return 0;
}


