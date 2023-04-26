#ifndef FIFONAME
#define FIFONAME "./reqFIFO"
#endif

#ifndef KEY_SHM
#define KEY_SHM 2222
#endif

#ifndef KEY_MQ
#define KEY_MQ 3333
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
}Infra;

typedef struct
{
    /* data */
    pid_t cpid;
    float result;
}Result;

typedef struct
{
    /* data */
    pid_t cpid; // client process PID
    int opr1; // operand 1
    int opr2; // operand 2
    char oper; // operation to perform
}Request;