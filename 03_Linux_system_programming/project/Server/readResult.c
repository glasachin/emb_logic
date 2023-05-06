#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

void* readResult(void *arg)
{
    // It needs shared memory and message queue
    char prfd[4];
    int fd, fret;
    Infra *infra;
    Request r;
    int ret;
    Result *res;
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif

    infra = (Infra*)arg;
    
    // while(1)
    // {
    // we took message from shared memory and sent it to message queue
    ret = msgsnd(infra->mqKey, infra->smptr, sizeof(float),0);
    if(ret == -1)
    {
        perror("msgsnd");
        pthread_exit("failure");
    }
    #ifdef DEBUG
        printf("%s:Read Result %d Bytes.\n",__func__, ret);
    #endif

    // }
    #ifdef DEBUG
        printf("%s: End.\n",__func__);
    #endif
    
    return (void*)0;
}