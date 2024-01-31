#include "headers.h"
#include "structure.h"
#include "declarations.h"

void *deleteNode(void *arg)
{
    Node *root, *parent;
    nodeInfo *temp;
    int val, nodePos;
    printf("%s: Init \n", __func__);

    printf("Enter the value to be deleted: \n");
    scanf("%d", &val);

    root = (Node *)arg;
    parent = root;
    nodePos = 0; // to identify left or right node of parent

    // Find the node to be deleted
    while (1)
    {
        if (!root)
        {
            nodePos = 0;
            break;
        }
        else if (val < root->data)
        {
            parent = root;
            root = root->left;
            continue;
        }
        else if (val > root->data)
        {
            parent = root;
            root = root->right;
            continue;
        }
        else
        {
            if (parent->left == root)
                nodePos = -1;
            else
                nodePos = 1;
            break;
        }
    }

    // delete the node
    if (nodePos == 0)
    {
        printf("Entered value not found in the tree.\n");
    }
    else if ((root->left == NULL) & (root->right == NULL))
    {
        // It is case 1 of deleteion.
        if (nodePos < 0)
        {
            // make left of parent as NULL
            parent->left = NULL;
        }
        else
        {
            parent->right = NULL;
        }
    }
    else if ((root->left == NULL) | (root->right == NULL))
    {
        // It is case 2 of deletion
        if (nodePos < 0)
        {
            parent->left = root->left;
        }
        else
        {
            parent->right = root->right;
        }
    }
    else
    {
        // It is case 3 of deletion
        // if(nodePos < 0)
        // {
        // find the largest value in the left sub-tree
        temp = (nodeInfo *)(*fptr[8])((void *)root->left);
        temp->node->left = root->left;
        temp->node->right = root->right;
        parent->left = temp->node;
        temp->parent->right = NULL; // deleted node which have been moved

        // temp->left = root->left;
        // temp->right = root->right;
        // parent->left = temp;
        // }
        // else
        // {
        //     // find the smallest value in the right sub-tree
        //     temp = (nodeInfo*)(*fptr[7])((void*)root);
        //     temp->node->left = root->left;
        //     temp->node->right = root->right;
        //     parent->right = temp->node;

        //     temp->parent->right = NULL; // deleted node which have been moved
        // }
    }

    printf("%s: End\n", __func__);

    return arg;
}