#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* createLinkList(void *arg)
{
    Node *start;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    if(arg)
    {
        printf("%s: Link List is already create.\n",__func__);
        return arg;
    }

    

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif

    return (*fptr[7])(0); //create Node 
}