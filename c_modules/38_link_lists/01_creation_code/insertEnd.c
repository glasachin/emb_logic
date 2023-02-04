#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* insertEnd(void *arg)
{
    Node *cur;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif
    
    cur = (Node*)arg;
    while(cur->next != NULL)
        cur = cur->next;

    cur->next = (Node*)(*fptr[7])(0);

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return 0;
}