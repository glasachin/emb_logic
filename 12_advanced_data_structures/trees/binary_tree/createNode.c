#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* createNode(void *arg)
{
    Node *new;
    int choice;
    printf("%s: Begin\n", __func__);

    if(arg != NULL)
    {
        printf("%s: Tree Already Created\n", __func__);
        return arg;
    }

    new = (Node*)malloc(sizeof(Node));
    if(!new)
    {
        perror("Malloc");
        (*fptr[0])((void*)"failure");
    }
    
    new->parent = NULL;
    new->children = NULL;
    new->status = ready;
    printf("%s: Please enter Value for new node: \n", __func__);
    scanf("%d", &new->value);

    printf("%s: End \n", __func__);
    return (void*)new;
}