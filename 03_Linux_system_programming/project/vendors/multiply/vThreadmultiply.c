#include"headers.h"
#include"declarations.h"

void* vThreadMultiply(void *arg)
{
    int pfd;
    Request r;
    int ret,fd;
    Result *res; 
    int smid;
    void *smptr;
    pthread_t thid;
    int smKey1;
    void *smptr1;
    sem_t tsem1;
    #ifdef DEBUG
        printf("%s:%s: Begin.\n",__FILE__, __func__);
    #endif

/*
    // Create and attach the shared memory
    smid = shmget((key_t)KEY_SHM, sizeof(Result), 0666|IPC_CREAT);
    if(smid == -1)
    {
        perror("shared memory error");
        exit(EXIT_FAILURE);
    }

    smptr = shmat(smid, NULL, 0);
    res = (Result*)smptr; // result will attach to shared memory
    
    res->result = (float)(r.opr1 + r.opr2);
    res->cpid = r.cpid;
*/

    smKey1 = shmget((key_t)KEY_SHM1, sizeof(sem_t), IPC_CREAT|0666);
    if(smKey1 == -1)
    {
        perror("shmget");
        // free(infra->pipe);
        // free(infra->fifoName);
        // free(infra);
        // (*fptr[0])((void*)"failure");
    }
    smptr1 = shmat(smKey1, NULL, 0);
    if(!smptr)
    {
        perror("shmget");
        // free(infra->pipe);
        // free(infra->fifoName);
        // free(infra);
        // (*fptr[0])((void*)"failure");
    }

    if(sem_post((sem_t*)smptr) == -1)
    {
        perror("sem_post");
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
        printf("%s: %s: END.\n",__FILE__, __func__);
    #endif
    
    return 0;
}
