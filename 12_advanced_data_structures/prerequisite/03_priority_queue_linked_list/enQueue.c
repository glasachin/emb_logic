#include "headers.h"
#include "declarations.h"

void *enQueue(void *arg)
{
    PQueue *pq, *npq;
    DataSet *ds;
    Item *im, *cur, *psl; // psl: pointer to second last
    printf("%s: Begin \n", __func__);

    pq = (PQueue *)arg;
    if (!pq)
    {
        printf("%s: Priority Queue Not found\n", __func__);
        return arg;
    }
    ds = (DataSet *)malloc(sizeof(DataSet));
    if (!ds)
    {
        perror("malloc");
        // (*fptr[1])((void*)"failure");
        return arg;
    }
    printf("%s: Enter Priority.\n", __func__);
    scanf("%d", &ds->priority);
    printf("%s: Enter Value\n", __func__);
    scanf("%d", &ds->value);

    // create Item
    im = (Item *)malloc(sizeof(Item));
    if (!im)
    {
        perror("malloc");
        return arg;
    }
    im->pnx = NULL;
    im->pds = ds;

    // assign first item, only if not assigned
    if (!pq->pfi)
    {
        pq->pfi = im;
        return (void *)pq;
    }

    // insert at location where priority is less
    psl = cur = pq->pfi; // contains the address of first item
    do
    {
        // find location by comparing the pirority of new item
        if (im->pds->priority < cur->pds->priority)
        {
            // insert here
            im->pnx = cur;
            psl->pnx = im;
            break;
        }
        if (cur->pnx)
        {
            psl = cur;
            cur = cur->pnx; // go to next item
        }
        else
        {
            // insert here at last
            cur->pnx = im;
            break;
        }

        // if (cur->pds->priority < ds->priority)
        //     cur = cur->pnx;
    } while (1);

    printf("%s: End \n", __func__);
    return (void *)pq;
}