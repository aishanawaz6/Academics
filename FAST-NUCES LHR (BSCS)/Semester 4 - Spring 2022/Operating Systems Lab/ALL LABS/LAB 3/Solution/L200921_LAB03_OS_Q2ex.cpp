#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <cstdlib>
using namespace std;
int main (int argc, char*argv[])
{
float sum=0;
for (int i=1;i<argc;i++)
{
sum=atof(argv[i])+sum;
}
float avg;
avg=sum/(argc-1);
cout<<"Average is : "<<avg<<endl;
return 0;
}