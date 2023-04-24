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
    char buffer[BUFSIZ];
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

    while(running)
    {
        while(shared_stuff->written_by_you == 1)
        {
            sleep(1);
            printf("Waiting for the client...\n");
        }
        printf("Enter some text: ");
        fgets(buffer,BUFSIZ,stdin);
        strncpy(shared_stuff->some_text, buffer, TEXT_SZ); // copied to the shared memory text variable
        shared_stuff->written_by_you = 1;
        if(strncmp(buffer, "end", 3) == 0)
        {
            running = 0;
        }
    }

    // detach the shared memroy
    if(shmdt(shared_memory) == -1)
    {
        perror("memory detach");
        exit(EXIT_FAILURE);
    }
    return 0;
}