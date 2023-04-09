#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

void* createInfra(void *arg)
{
    int ret;
    Infra *infra;
    #ifdef DEBUG
        printf("%s: Begin.\n",__func__);
    #endif

    infra = (Infra*)malloc(sizeof(Infra));
    if(!infra)
    {
        perror("malloc");
        (*fptr[0])((void*)"failure"); // Failure Message
    }

    // Infra contains four IPC, we need to create for every one
    //1. allocate space of pipes
    infra->pipe = (int*)malloc(sizeof(int)*2);
    if(!infra->pipe)
    {
        perror("pipe");
        free(infra);
        (*fptr[0])((void*)"failure");
    }

    // 2. Allocate space for FIFO
    infra->fifoName = (char*)malloc(sizeof(char)*20); //max 20 for fifo name
    if(!infra->fifoName)
    {
        perror("FIFO");
        free(infra->pipe);
        free(infra);
        (*fptr[0])((void*)"failure");
    }
    memset(infra->fifoName, '\0', 20); //set memory for fifoName space

    // 3, 4: Set value of shared memory and message queue
    infra->smKey = infra->mqKey = 0;

    // Now, create Pipe
    ret = pipe(infra->pipe);
    if(ret == -1)
    {
        perror("pipe");
        free(infra->pipe);
        free(infra->fifoName);
        free(infra);
        (*fptr[0])((void*)"failuer");
    }

    // Create FIFO
    ret = mkfifo(FIFONAME, 0666);
    if(ret == -1)
    {
        perror("mkfifo");
        free(infra->pipe);
        free(infra->fifoName);
        free(infra);
        (*fptr[0])((void*)"failure");
    }

    // Create shared memory
    infra->smKey = shmget((key_t)KEY_SHM, sizeof(Result), IPC_CREAT|0666);
    if(infra->smKey == -1)
    {
        perror("shmget");
        free(infra->pipe);
        free(infra->fifoName);
        free(infra);
        (*fptr[0])((void*)"failure");
    }

    // Create Message Queue
    infra->mqKey = msgget((key_t)KEY_MQ, IPC_CREAT|0666);
    if(infra->mqKey == -1)
    {
        perror("msgget");
        free(infra->pipe);
        free(infra->fifoName);
        free(infra->smKey);
        free(infra->mqKey);
        (*fptr[0])((void*)"failure");
    }
    
    
    #ifdef DEBUG
        printf("%s: End.\n", __func__);
    #endif
    return (void*)infra;
}
