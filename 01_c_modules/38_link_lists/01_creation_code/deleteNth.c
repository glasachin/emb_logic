#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* deleteNth(void *arg)
{
    Node *cur, *new;
    int pos;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif
    
    cur = (Node*)arg;
    printf("Enter the Position for new node: ");
    scanf("%d",&pos);

    while((cur->next)->next != NULL)
    {
        cur = cur->next;
        pos -= 1;
        if(pos==1)
            break;
    }

    if(pos == 1)
    {
        new = (Node*)(*fptr[7])(0);
        new->next = cur->next;
        cur->next = new;
    }
    else if(pos == 0)
    {
        printf("not allowed to insert at 0th location.\n");
    }
    else
    {
        printf("Position is out of list length\n.");
    }
    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return 0;
}