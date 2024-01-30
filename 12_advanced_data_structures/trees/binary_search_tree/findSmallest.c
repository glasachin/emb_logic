/**
 * Leftmost node of Left sub-tree is the smallest node
*/

#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* findSmallest(void* arg)
{
    Node* root;
    int smallest;

    printf("%s: Init \n", __func__);

    root = (Node*)arg;

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
            root = root->left;
        }
    }

    printf("Smallest Number is: %d\n", smallest);
    printf("%s: End\n", __func__);
    return arg;
}