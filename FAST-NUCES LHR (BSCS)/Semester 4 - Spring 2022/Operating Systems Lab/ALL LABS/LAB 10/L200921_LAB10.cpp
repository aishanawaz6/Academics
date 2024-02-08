//20L0921 AISHA MUHAMMAD NAWAZ BSCS SECTION 4A1 OS SPRING 2022 
#include <iostream>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
using namespace std;

sem_t mutex; // to ensure mutual exclusion
int tellstate[3]; // Basically tells the 3 states: thinking,hungry & eating.
int thinking=0,hungry=1,eating=2;
sem_t chopstick[5]; // 5 chopsticks in total on the table

//Note: p_num means Philosopher number

void checkIT(int p_num)
{
	int left=(p_num + 4)%5;
	int right=(p_num +1)%5;
	
	if (tellstate[p_num]==hungry && tellstate[left]!=eating && tellstate[right]!=eating)
	{
		tellstate[p_num]=eating;
		sleep(2);
		cout<<"Philosopher "<<p_num+1<<" takes chopstick "<<left+1<<" and "<<p_num+1<<endl;
		cout<<"Philosopher "<<p_num+1<<" is Eating"<<endl;
		sem_post(&chopstick[p_num]);
	}	
}
void pickchopstick(int p_num)
{
	sem_wait(&mutex);
	
	tellstate[p_num]=hungry;
	cout<<"Philosipher"<<p_num+1<<" wants to eat"<<endl;
	
	checkIT(p_num);	
	sem_post(&mutex);
	
	sem_wait(&chopstick[p_num]);
	sleep(1);
}

void dropchopstick(int p_num)
{
	sem_wait(&mutex);
	
	tellstate[p_num]=thinking;
	
	int left=(p_num + 4)%5;
	int right=(p_num +1)%5;
	
	cout<<"Philosopher "<<p_num+1<<" drops choptick "<<left+1<<" and "<<p_num+1<<endl;
	cout<<"Philospher "<<p_num+1<<" is Thinking"<<endl;
	
	checkIT(left);
	checkIT(right);
	
	sem_post(&mutex);	
}


void *philosophers(void* num)
{
while (true)
{
	int * i=(int*) num;
	sleep(1);
	pickchopstick(*i);
	sleep(0);	
	dropchopstick(*i);
}
}

int main() //Main function
{


int philosopher[5]={0,1,2,3,4}; // 5 philosophers total. So array of size 5 created.
pthread_t T[5]; // 5 ids shall be stored for 5 threads.

sem_init(&mutex,0,1); //Intializing mutex semaphore.


for (int i=0;i<5;i++) //Intializing chopstick semaphores (5).
	sem_init(&chopstick[i],0,0); 


for (int i=0;i<5;i++)
{
	pthread_create(&T[i],NULL,philosophers,&philosopher[i]); // Creating required threads. 5 in this case.
	cout<<"Philosopher "<<i+1<<" is Thinking"<<endl; //As threads created philosophers start thinking.
	
}

for (int i=0;i<5;i++) //Joining threads.
	pthread_join(T[i],NULL);

return 0;
}
