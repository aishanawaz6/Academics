#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main()
{

char line[225];
char* token;

int i=0;
long int sum=0,idle,lastsum=0,lastIdle=0;
long double idleFraction;

while(1)
{

FILE*f1=fopen("/proc/stat","r");
i=0;
fgets(line,225,f1);
printf("Full Line:  %s\n",line);
fclose(f1);

token=strtok(line," ");
sum=0;

while(token!=NULL)
{

token=strtok(NULL," ");

if(token!=NULL)
{
if(i==0)
printf("user: %s\n",token);
if(i==1)
printf("nice: %s\n",token);
if(i==2)
printf("system: %s\n",token);
if(i==3)
printf("idle: %s\n",token);
if(i==4)
printf("iowait: %s\n",token);
if(i==5)
printf("irq: %s\n",token);
if(i==6)
printf("softirq: %s\n",token);

sum=sum+atoi(token);

if(i==3)
idle=atoi(token);

i++;

}
}
idleFraction = 100-(idle-lastIdle)*100.0/(sum-lastsum);
printf("CPU UTILIZATION: %Lf %% \n",idleFraction);

lastIdle=idle;
lastsum=sum;
sleep(1);
}
return 0;
}