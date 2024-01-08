#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* inOrderTraverse(void* arg)
{
    Node *tree;
    printf("%s: Init \n", __func__);

    tree = (Node*)arg;

    if(tree != NULL)
    {
        inOrderTraverse(tree->left); // recursive
        printf("%d\t", tree->data);
        inOrderTraverse(tree->right);
    }

    printf("%s: End\n", __func__);
    return 0;
}