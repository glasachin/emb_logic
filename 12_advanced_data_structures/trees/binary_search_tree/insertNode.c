/**
 * If tree is not created then we will return first node as a root to the tree.
 * otherwise we will insert node in the tree at specific location
 */
#include "headers.h"
#include "structure.h"
#include "declarations.h"

void *insertNode(void *arg)
{
    int val;
    Node *ptr, *root, *currentNode;
    printf("%s: Init \n", __func__);

    root = (Node *)arg;

    // allocate space for node
    ptr = (Node *)malloc(sizeof(Node));
    if (!ptr)
    {
        perror("malloc");
        (*fptr[0])((void *)"Failure");
    }

    printf("Enter value of the node: \n");
    scanf("%d", &val);
    ptr->data = val;
    ptr->left = NULL;
    ptr->right = NULL;

    if (!root)
    {
        root = ptr;
    }
    else
    {
        // find location to put the newly created node, starting from the root
        currentNode = root;
        while (1)
        {
            if (ptr->data >= currentNode->data)
            {
                if(!currentNode->right)
                {
                    currentNode->right = ptr;
                    break;
                }
                currentNode = currentNode->right;
            }
            else
            {
                if(!currentNode->left)
                {
                    currentNode->left = ptr;
                    break;
                }
                currentNode = currentNode->left;
                
            }
        }
    }

    printf("%s: End\n", __func__);
    return (void *)root;
}