#include"headers.h"
#include"declarations.h"

int main(int argc, char *argv[])
{
    int pfd;
//     Request r;
//     int ret,fd;
//     Result *res; 
//     int smid;
    void *smptr;
    pthread_t thid;
    void *thread_result;
    int ret, smid;
    DataToProcess data;

    #ifdef DEBUG
        printf("%s:%s: Begin.\n",__FILE__, __func__);
    #endif

    if(argc != 2)
    {
        printf("Error: Pipe fd not received\n");
        return -1;
    }
    pfd = atoi(argv[1]);
    
    #ifdef DEBUG
        printf("%s:%s: Pipe fd: %d \n",__FILE__, __func__, pfd);
    #endif

    // ret = read(data.pfd, &data.req, sizeof(Request));
    // if(ret == -1)
    // {
    //     perror("read");
    //     exit(EXIT_FAILURE);
    // }
    // #ifdef DEBUG
    //     printf("%s: %s: Read Request %d Bytes.\n",__FILE__, __func__, ret);
    // #endif

    // if(data.req.oper != '+')
    // {
    //     printf("Wrong operand\n");
    //     return 0;
    // }

    // create thread
    if(pthread_create(&thid, 0 , vThreadAdder, (void*)&pfd) == -1)
    {
        perror("ptrhead_vendor create");
        exit(EXIT_FAILURE);
    }

    pthread_join(thid, &thread_result);
    printf("Thread joined: \n");
    // // Create and attach the shared memory
    // smid = shmget((key_t)KEY_SHM, sizeof(Result), 0666|IPC_CREAT);
    // if(smid == -1)
    // {
    //     perror("shared memory error");
    //     exit(EXIT_FAILURE);
    // }

    // smptr = shmat(smid, NULL, 0);
    // data.res = (Result*)smptr; // result will attach to shared memory
    
    // data.res->result = (float)(r.opr1 + r.opr2);
    // data.res->cpid = r.cpid;

    #ifdef DEBUG
        printf("%s: %s: END.\n",__FILE__, __func__);
    #endif
    
    return 0;
}
