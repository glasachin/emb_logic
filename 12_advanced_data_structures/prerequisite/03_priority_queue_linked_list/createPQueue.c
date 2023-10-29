#include "headers.h"
#include "declarations.h"

void* createPQueue(void *arg)
{
    PQueue *pq;

    printf("%s: Begin \n", __func__);

    if(arg != NULL)
    {
        printf("%s: Queue already created\n", __func__);
        return arg;
    }

    pq = (PQueue*)malloc(sizeof(PQueue));
    if(!pq)
    {
        perror("Malloc");
        (*fptr[1])((void*)"Failure");
    }

    pq->pfi = NULL;
    pq->count = 0;

    printf("%s: End ", __func__);
    return (void*)pq;
}