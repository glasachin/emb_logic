#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

void* processRequest(void *arg)
{
    int fd;
    Infra *infra;
    Request r;
    int ret;
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif

    infra = (Infra*)arg;
    fd = open(FIFONAME, O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        (*fptr[0])((void*)"failure");
    }

    #ifdef DEBUG
        printf("%s: Request FIFO Opened. fd: %d\n",__func__, fd);
    #endif

    ret = read(fd, &r, sizeof(Request));
    if(ret == -1)
    {
        perror("read");
        (*fptr[0])((void*)"failure");
    }

    #ifdef DEBUG
        printf("%s: Read server bytes: %d\n",__func__, ret);
    #endif

    // close the opened FIFO fd
    close(fd);

    // release the semaphore
    sem_post(&infra->tsem);
    printf("Semaphore released\n");

    #ifdef DEBUG
        printf("%s: End.\n",__func__);
    #endif
    return 0;
}