#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* deleteNode(void* arg)
{
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    // call deleteMenu
    (*fptr[13])(arg);

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return 0;
}