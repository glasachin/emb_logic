#include "headers.h"
#include "declarations.h"

PQueue* createNode()
{
    PQueue *pq;

    printf("%s: Begin \n", __func__);

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