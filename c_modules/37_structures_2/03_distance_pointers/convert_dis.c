#include"headers.h"
#include"declarations.h"

void convert_dis(dis *d)
{
    #ifdef DEBUG
        printf("Starting: %s\n",__func__);
    #endif

    *d->dm->cm = (*d->dfi->ft*12+*d->dfi->inch)*2.56;
    *d->dm->m = (int)*d->dm->cm/100;
    *d->dm->cm -= *d->dm->m*100;
}