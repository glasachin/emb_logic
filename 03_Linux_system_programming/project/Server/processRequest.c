#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

void* processRequest(void *arg)
{
    char prfd[2];
    int fd, fret;
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

    // release the semaphore
    sem_post(&infra->tsem);
    printf("Semaphore released\n");

    // fork to run new operation
    fret = fork();
    switch(fret)
    {
        case -1:
            perror("fork");
            (*fptr[0])((void*)"fialure");
            break;
        case 0:
            sprintf(prfd,"%d",*(infra->pipe)+0);
            execl("./adder","adder",prfd, NULL);
            printf("%s: Error: execl() failed\n", __func__, ret);
        default:
            ret = write(*(infra->pipe)+1,&r,sizeof(Request));
            if(ret == -1)
            {
                perror("read");
                (*fptr[0])((void*)"failure");
            }
            printf("%s:%s: Wrote Request %d Bytes \n", __FILE__,__func__, ret);
    }

    // close the opened FIFO fd
    close(fd);
    #ifdef DEBUG
        printf("%s: End.\n",__func__);
    #endif
    return 0;
}