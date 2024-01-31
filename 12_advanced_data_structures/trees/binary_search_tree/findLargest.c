// we will be returning the largest node address from here
#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* findLargest(void* arg)
{
    Node *root, *parent;
    int largest;
    nodeInfo *info;
    printf("%s: Init \n", __func__);

    root = (Node*)arg;
    parent = root;
    if(!root->right)
    {
        largest = root->data;
    }
    else
    {
        while(1)
        {
            if(!root->right)
            {
                largest = root->data;
                break;
            }
            parent = root;
            root = root->right;
        }
    }

    printf("Largest Node Value is: %d\n", largest);
    info->node = root;
    info->parent = parent;

    printf("%s: End\n", __func__);
    return (void*)info;
}