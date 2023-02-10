#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* createNode(void* arg)
{
    Node *new;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    new = (Node*)malloc(sizeof(Node));
    if(new == NULL)
    {
        perror("malloc");
        (*fptr[1])((void*)"Failure"); //exit Program
    }
    new->info = rand() % 100;
    new->next = NULL;
    #ifdef DEBUG
        printf("%s: End\n",__func__);
    #endif
    return (void*)new;
}