#include"headers.h"
#include"declarations.h"
#include"structure.h"

void* displayLinkList(void *arg)
{
    Node* cur;
    int i=0;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    cur = (Node*)arg;
    while(cur->next != NULL)
    {
        printf("Node: %d, info: %d\n",i,cur->info);
        cur = cur->next;
        i+=1;
    }

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif

    return 0;
}