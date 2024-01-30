#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* findLargest(void* arg)
{
    Node* root;
    int largest;
    printf("%s: Init \n", __func__);

    root = (Node*)arg;

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
            root = root->right;
        }
    }

    printf("Largest Node Value is: %d\n", largest);
    printf("%s: End\n", __func__);
    return arg;
}