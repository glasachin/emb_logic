#include"headers.h"
#include"declarations.h"

void* vThreadAdder(void *arg)
{
    int pfd;
    Request req;
    int ret,fd;
    Result *res; 
    int smid;
    void *smptr;
    pthread_t thid;
    int smKey1;
    void *smptr1;
    sem_t tsem1;
    // DataToProcess *data;

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
    pfd = *(int*)arg;
    // data = (DataToProcess*)arg;

    smKey1 = shmget((key_t)KEY_SHM1, sizeof(sem_t), IPC_CREAT|0666);
    if(smKey1 == -1)
    {
        perror("vThread error: shmget");
        exit(EXIT_FAILURE);
    }

    smptr1 = shmat(smKey1, NULL, 0);
    if(!smptr1)
    {
        perror("vThread error: shmat smptr1");
        exit(EXIT_FAILURE);
    }

    ret = read(pfd, &req, sizeof(Request));
    if(ret == -1)
    {
        perror("vThread error: read pipe");
        exit(EXIT_FAILURE);
    }
    #ifdef DEBUG
        printf("%s: %s: Read Request %d Bytes.\n",__FILE__, __func__, ret);
    #endif

    printf("Received adder operator: \n", req.oper);
    if(req.oper != '+')
    {
        printf("%s: Wrong operand\n", __FILE__);
        return 0;
    }

    // release semaphore
    if(sem_post((sem_t*)smptr1) == -1)
    {
        perror("vThread error: sem_post");
        exit(EXIT_FAILURE);
    }
    printf("Adder Semaphore released.\n");

    #ifdef DEBUG
        printf("%s: %s: END.\n",__FILE__, __func__);
    #endif
    
    return 0;
}
