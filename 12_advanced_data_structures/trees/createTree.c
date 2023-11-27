#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* createTree(void *arg)
{
    Node *root;
    int choice;
    printf("%s: Begin\n", __func__);

    if(arg != NULL)
    {
        printf("%s: Tree Already Created\n", __func__);
        return arg;
    }

    // root = createNode();
    

    printf("%s: End \n", __func__);
    return arg;
}