/**
 * Leftmost node of Left sub-tree is the smallest node
*/
// we will be returning the smallest node address from here
#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* findSmallest(void* arg)
{
    Node* root, *parent;
    int smallest;
    nodeInfo *info;

    printf("%s: Init \n", __func__);

    root = (Node*)arg;
    parent = root;

    if(!root->left)
    {
        smallest = root->data;
    }
    else
    {
        while(1)
        {
            if(!root->left)
            {
                smallest = root->data;
                break;
            }
            parent = root;
            root = root->left;
        }
    }

    printf("Smallest Number is: %d\n", smallest);
    info->node = root;
    info->parent = parent;

    printf("%s: End\n", __func__);
    return (void*)info;
}