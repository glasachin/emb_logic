/**
 * we will create new node at 0 then move it to other location
 */
#include "headers.h"
#include "declarations.h"
#include "structures.h"
int tempPower(int a, int b);

void **insertNode(void **arg)
{
    Node **tree;
    int i, n;

    printf("%s: Begin\n", __func__);

    // call create node function
    tree = (Node **)arg;
    if (*(tree + 1) == NULL)
    {
        printf("%s: Tree Not found.'\n", __func__);
        return arg;
    }

    *(tree + 0) = (Node *)(*fnptr[1])(0); // put new node at 0 location temperarily

    for( i = tempPower(2, treeLevel); i < tempPower(2,treeLevel+1); i++)
    {
        if(*(tree + i) == NULL)
        {
            *(tree + i) = *(tree + 0);
            *(tree + 0) = NULL;
            break;
        }
    }
    if( i == tempPower(2,treeLevel+1) )
    {
        treeLevel += 1;
        tree = (Node **)realloc(tree, sizeof(Node *) * ( 2*i));
        if (!tree)
        {
            perror("insertnode: realloc");
            (*fnptr[0])((void *)"failure");
        }
        memset(tree + i, '\0', sizeof(Node *) * (i));
        *(tree + i) = *(tree + 0);
        *(tree + 0) = NULL;
        printf("power = %d\n", tempPower(2,treeLevel));
        printf("Allocated new size\n");
    }


    // traverse tree to insert the node at any left or right side
    // for (i = n = 1; i < 2 * n + 1; i++, n++)
    // i = 1;
    // while(1)
    // {
    //     if (*(tree + i) == NULL)
    //     {
    //         printf("added node at 0\n");
    //         *(tree + i) = *(tree + 0);
    //         *(tree + 0) = NULL;
    //     }
    //     else if (*(tree + (2 * i)) == NULL)
    //     {
    //         printf("added node at 1\n");
    //         *(tree + (2 * i)) = *(tree + 0);
    //         *(tree + 0) = NULL;
    //         break;
    //     }
    //     else if (*(tree + (2 * i + 1)) == NULL)
    //     {
    //         printf("added node at 2\n");
    //         *(tree + (2 * i + 1)) = *(tree + 0);
    //         *(tree + 0) = NULL;
    //         break;
    //     }
    //     else
    //     {
    //         printf("added node at 3\n");
    //         tree = (Node **)realloc(tree, sizeof(Node *) * (2 * (i + 1) + 2));
    //         // printf("tree size: %ld\n", sizeof(tree));
    //         if (!tree)
    //         {
    //             perror("insertnode: realloc");
    //             (*fnptr[0])((void *)"failure");
    //         }
    //         memset((tree + (2 * (i + 1))), '\0', sizeof(Node *) * (2 * (i + 1) + 1));
    //         // break;
    //     }

    //     // *(tree + 0) = NULL;
    //     printf("added node at 4\n");
    //     i++;
    // }

    printf("%s: End \n", __func__);
    return (void **)tree;
}


int tempPower(int a, int b)
{
    int i = 0, res = 1;
    for( i = 0; i < b; i++)
    {
        res  *= a;
    }
    return res;
}