#include"headers.h"
#include"structures.h"
#include"declarations.h"

void* createTree(void *arg)
{
    Node* avl;
    printf("%s: Start\n", __func__);

    avl = (Node*)arg;

    if(!avl)
    {
        avl = (*fptr[CREATE_NODE])((void*)0);
    }
    else
    {
        printf("%s: Tree has been already created..\n", __func__);
    }
    
    printf("%s: End\n", __func__);
    return (void*)avl;
}