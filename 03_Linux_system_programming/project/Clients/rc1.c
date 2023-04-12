#include"../Common/headers.h"
#include"../Common/dataStructure.h"


int main()
{
    int fd;
    int ret;
    Request r;
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
    }

    #ifdef DEBUG
        printf("%s: Wrote %d bytes into FIFO.\n", __func__, ret);
    #endif

    #ifdef DEBUG
        printf("%s: END.\n", __func__);
    #endif
    
    return 0;
}
