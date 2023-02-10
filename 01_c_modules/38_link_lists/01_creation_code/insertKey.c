#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* insertKey(void *arg)
{
    Node *cur, *new;
    int key;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif
    
    cur = (Node*)arg;
    printf("Enter the key value: ");
    scanf("%d",&key);
    while((cur->next)->info != key)
    {
        cur = cur->next;
        if(cur->next == NULL)
        {
            printf("Key not found! \n");
            break;
        }
    }

    if(cur->next != NULL)
    {
        new = (Node*)(*fptr[7])(0);
        new->next = cur->next;
        cur->next = new;
    }


    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return 0;
}