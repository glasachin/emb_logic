#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* deleteKey(void *arg)
{
    Node *cur, *del;
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
            return 0;
        }
    }

    del = cur->next;
    cur->next = del->next;
    del->next = NULL;
    free(del);

    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return 0;
}