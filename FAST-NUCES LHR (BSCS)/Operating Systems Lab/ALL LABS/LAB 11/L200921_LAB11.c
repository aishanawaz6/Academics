//In terminal write gcc code.c -o a.out -lpthread and then ./a.out
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/wait.h>

int main(int argc,char*argv[])
{
if(argc<=1) //If no input from user then exit.
{
puts("NO INPUT!");
return 0;
}
    int i;
    key_t shm_key;
    int shm_id;
    int *shrd_value; //Will keep track of processes intialized and waiting execution.
   
    pid_t pid;
    int fork_count=atoi(argv[1]);
   
    sem_t *sem;
    sem_t *mutex;
   
    unsigned int sem_value=0;
    unsigned int sem_value2=1;
   
    shm_key = ftok("/dev/null", 65);
    shm_id = shmget(shm_key, sizeof(int), 0644 | IPC_CREAT);
    if (shm_id < 0)
    {
        perror("shmgget");
        exit(EXIT_FAILURE);
    }
    shrd_value = shmat(shm_id, NULL, 0);
    *shrd_value = 0;
 
    sem = sem_open("semaphore", O_CREAT | O_EXCL, 0644, sem_value);
    mutex = sem_open("semaphore2", O_CREAT | O_EXCL, 0644, sem_value2); //Works like mutex
   
    printf("You want %d processes.\n",fork_count);

    for (i = 0; i < fork_count; i++)
    {
        sleep(1);  // take time to intialize processes.
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            sem_unlink("semaphore");
            sem_close(sem);
            sem_unlink("semaphore2");
            sem_close(mutex);
            exit(EXIT_FAILURE);
        }
        else if (pid == 0) // to ensure child that has been created does not create further childrens.
        {
           printf("Process - %d has been intialized\n", i);
           break;
        }
    }
    if (pid == 0)
    {
     
     sem_wait(mutex); //Works Like mutex
     sleep(1);
     printf("Process - %d is waiting to execute..\n", i);
     *shrd_value += 1;
   
     if(*shrd_value==fork_count)
    {
    printf("All Processes has been intialized & are waiting to execute.\n");
    for(int i=0;i<fork_count;i++) //Let them execute
    sem_post(sem);
    }
    sem_post(mutex);
       
        //Process starts exection here..
        sem_wait(sem);
        printf("Process- %d is executing..\n", i);
        sleep(3); //Takes time to execute
        printf("Process - %d is done executing..\n", i);
        sem_post(sem); //release
       
        exit(EXIT_SUCCESS);
    }
    else if (pid > 0)
    {
        //parent process
        while (pid = waitpid(-1, NULL, 0)) // to ensure that if this is the parent of the child it waits for all its other childrens to exit
        {
            if (errno == ECHILD)
            {
                break;
            }
        }
        puts("All processes exited");
        shmdt(shrd_value);
        shmctl(shm_id, IPC_RMID, 0);
        sem_unlink("semaphore"); // removes named semaphore
        sem_close(sem);          // frees resources
        sem_unlink("semaphore2"); // removes named semaphore
        sem_close(mutex);          // frees resources
 
        exit(0);
    }
}