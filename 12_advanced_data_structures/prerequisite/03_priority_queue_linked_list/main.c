#include "headers.h"
#include "declarations.h"

int main()
{
    PQueue *pq;

    printf("%s: Begin \n", __func__);
    pq = NULL;

    init();

    while(1)
        pq = (PQueue*)(*fptr[0])((void*)pq);

    printf("%s: End ", __func__);
    return 0;
}