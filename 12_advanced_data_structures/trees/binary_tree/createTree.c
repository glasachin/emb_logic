#include"headers.h"
#include"declarations.h"
#include"structures.h"

void** createTree(void **arg)
{
    Node *root, *new;
    int choice;
    printf("%s: Begin\n", __func__);

    if(arg != NULL)
    {
        printf("%s: Tree Already Created\n", __func__);
        return arg;
    }

    // root = createNode();
    new = (Node*)(*fptr[6])(0);
    

    tree = (Node**)realloc();

    printf("%s: End \n", __func__);
    return arg;
}