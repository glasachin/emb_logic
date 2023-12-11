#include "headers.h"
#include "declarations.h"

void* display(void *arg)
{
    PQueue *pq;
    Item *cur;

    printf("%s: Begin \n", __func__);

    pq = (PQueue*)arg;
    if(!pq->pfi)
    {
        printf("%s: Priority queue is empty\n",__func__);
        return arg;
    }

    cur = pq->pfi;

    while(1)
    {
        printf("%s: priority: %3d: value%3d\n",__func__, cur->pds->priority, cur->pds->value);
        if(cur->pnx)
            cur = cur->pnx;   
        else
            break;
    }
    
    printf("%s: End \n", __func__);
    return (void*)pq;
}