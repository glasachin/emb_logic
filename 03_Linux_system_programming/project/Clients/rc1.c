#include"../Common/headers.h"
#include"../Common/dataStructure.h"


int main()
{
    int fd;
    int ret;
    Request r;
    int mqKey;
    Result *res;
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif

    fd = open(FIFONAME, O_WRONLY);
    if(fd == -1)
    {
        perror("open");
    }

    #ifdef DEBUG
        printf("%s: Request FIFO Opened. fd: %d\n",__func__, fd);
    #endif

    // writing into fifo
    r.cpid = getpid();
    r.opr1 = 55;
    r.opr2 = 33;
    r.oper = '+';
    ret = write(fd, &r, sizeof(Request));
    if(ret == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // receive data from message queue
    mqKey = msgget((key_t)KEY_MQ, IPC_CREAT|0666);
    if(mqKey == -1)
    {
        perror("msgKey");
        exit(EXIT_FAILURE);
    }

    if((msgrcv(mqKey, (void*)res, sizeof(float), 0, 0)) == -1) // same message type as was in the sender and ignoring the msg type
    {
        perror("Message Read");
        exit(EXIT_FAILURE);
    }

    printf("CPID: %d, Result is: %0.2f\n",res->cpid,res->result);

    #ifdef DEBUG
        printf("%s: Wrote %d bytes into FIFO.\n", __func__, ret);
    #endif

    



    #ifdef DEBUG
        printf("%s: END.\n", __func__);
    #endif
    
    return 0;
}
