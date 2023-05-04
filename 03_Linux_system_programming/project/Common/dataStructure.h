#ifndef FIFONAME
#define FIFONAME "./reqFIFO"
#endif

#ifndef KEY_SHM
#define KEY_SHM 2222
#endif

#ifndef KEY_MQ
#define KEY_MQ 3333
#endif

#ifndef KEY_SHM1
#define KEY_SHM1 1111
#endif

typedef struct
{
    /* data */
    int *pipe; // Pipes
    char *fifoName; // FIFO
    int mqKey; //message queue
    int smKey; // shared memory 
    void *smptr;
    sem_t tsem;

    // for shared semaphore through shared memory
    int smKey1;
    void *smptr1;
    sem_t tsem1;

}Infra;

typedef struct
{
    /* data */
    long cpid;
    float result;
}Result;

typedef struct
{
    /* data */
    long cpid; // client process PID
    int opr1; // operand 1
    int opr2; // operand 2
    char oper; // operation to perform
}Request;