#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* deleteBeg(void *arg)
{
    Node *cur, *del_node;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif
    // 0th node is treated as a index node. So, beginning is after 0th node
    cur = ((Node*)arg);
    // new = (Node*)(*fptr[7])(0);

    if(cur->next == NULL)
        printf("There is no node in the list.\n");
    else
    {
        del_node = cur->next;
        cur->next = del_node->next;
        del_node->next = NULL;
        free(del_node);
    }
    
    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return (void*)arg;
}