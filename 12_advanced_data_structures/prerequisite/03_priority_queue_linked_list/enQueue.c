#include "headers.h"
#include "declarations.h"

void* enQueue(void *arg)
{
    PQueue *pq, *npq;
    DataSet *ds;
    Item *im;
    printf("%s: Begin \n", __func__);

    pq = (PQueue*)arg;
    if(!pq)
    {
        printf("%s: Priority Queue Not found\n", __func__);
        return arg;
    }
    ds = (DataSet*)malloc(sizeof(DataSet));
    if(!ds)
    {
        perror("malloc");
        (*fptr[0])((void*)"failure");
    }
    printf("%s: Enter Priority.\n", __func__);
    scanf("%d", ds->priority);
    printf("%s: Enter Value\n",__func__);
    scanf("%d", ds->value);

    // create Item
    im = (Item*)malloc(sizeof(Item));
    im->pnx = NULL;
    im->pds = ds;
    
    // assign first item, only if not assigned
    if(!pq->pfi)
        pq->pfi = im;

    printf("%s: End ", __func__);
    return (void*)pq;
}