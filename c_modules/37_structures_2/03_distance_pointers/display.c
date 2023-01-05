#include"headers.h"
#include"declarations.h"

void display(dis *d)
{
    #ifdef DEBUG
        printf("Starting Function: %s\n",__func__);
    #endif
    printf("Values in Feet & Inches: ");
    printf("%d, %d\n", *d->dfi->ft, *d->dfi->inch);

    printf("Values in m & cm: ");
    printf("%d, %0.2f\n", *d->dm->m, *d->dm->cm);

    #ifdef DEBUG
        printf("Ending Function: %s\n", __func__);
    #endif
}