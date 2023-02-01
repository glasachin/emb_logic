#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* insertNode(void *arg)
{
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    // call insertMenu
    (*fptr[8])(arg);

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return 0;
}