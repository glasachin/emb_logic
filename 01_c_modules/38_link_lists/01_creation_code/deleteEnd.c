#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* deleteEnd(void *arg)
{
    Node *cur;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif
    
    cur = (Node*)arg;
    if(cur->next == NULL)
    {
        printf("Nothing to delete.\n");
        return 0;
    }

    while((cur->next)->next != NULL)
    {
        cur = cur->next;
    }
    free(cur->next);
    cur->next = NULL; // deleted end node

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return 0;
}