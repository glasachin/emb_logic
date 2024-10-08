#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include"shm_com.h"

int main()
{
    int running = 1;
    void *shared_memory = (void*)0;
    struct shared_use_st *shared_stuff;
    int shmid;

    srand((unsigned int)getpid());

    // create shared memory segment
    shmid = shmget((key_t)1234, sizeof(struct shared_use_st), 0666|IPC_CREAT);
    if(shmid == -1)
    {
        perror("shared memory");
        exit(EXIT_FAILURE);
    }

    // attach shared memory
    shared_memory = shmat(shmid, (void *)0, 0);
    if(shared_memory == (void *) -1 )
    {
        perror("Memory attach");
        exit(EXIT_FAILURE);
    }
    printf("Memory attached at %X\n", (int)shared_memory);

    // assign shared memory to structure pointer
    shared_stuff = (struct shared_use_st *)shared_memory;
    shared_stuff->written_by_you = 0;
    while(running)
    {
        if(shared_stuff->written_by_you)
        {
            printf("You wrote: %s", shared_stuff->some_text);
            sleep(rand() % 4); //Make the other process wait for us
            shared_stuff->written_by_you = 0;
            if(strncmp(shared_stuff->some_text, "end", 3) == 0)
            {
                running = 0;
            }
        }
    }

    // detach the shared memroy
    if(shmdt(shared_memory) == -1)
    {
        perror("memory detach");
        exit(EXIT_FAILURE);
    }

    if(shmctl(shmid, IPC_RMID, 0) == -1)
    {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }
    return 0;
}