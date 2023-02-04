#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* insertBeg(void *arg)
{
    Node *cur, *new;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif
    // 0th node is treated as a index node. So, beginning is after 0th node
    cur = ((Node*)arg);
    new = (Node*)(*fptr[7])(0);
    
    if(cur->next != NULL)
    {
        new->next = cur->next;
        cur->next = new;
    }
    else
        ((Node*)arg)->next = new;

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return (void*)arg;
}