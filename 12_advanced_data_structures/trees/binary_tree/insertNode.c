#include "headers.h"
#include "declarations.h"
#include "structures.h"

void **insertNode(void **arg)
{
    Node **tree;
    int i, n;

    printf("%s: Begin\n", __func__);

    // call create node function
    tree = (Node**)arg;
    if(*(tree+1) == NULL)
    {
        printf("%s: Tree Not found.'\n", __func__);
        return arg;
    }
    *(tree + 0) = (*fptr[1])(0); // put new node at 0 location temperarily

    // traverse tree to insert the node at any left or right side
    for (i = n = 1; i < 2 * n + 1; i++, n++)
    {
        if (*(tree + i) == NULL)
        {
            *(tree + i) = *(tree + 0);
            *(tree+0) = NULL;
        }
        else if (*(tree + (2 * i)) == NULL)
        {
            *(tree + (2*i)) = *(tree + 0);
            *(tree+0) = NULL;
        }
        else if (*(tree + (2 * i + 1)) == NULL)
        {
            *(tree + (2*i+1)) = *(tree + 0);
            *(tree+0) = NULL;
        }
        else
        {
            tree = (Node**)realloc(tree, sizeof(Node*)*(2*(i+1)+1));
            if(!tree)
            {
                perror("insertnode: realloc");
                (*fnptr[0])((void*)"failure");
            }
            memset(*(tree+(2*(i+1))), '\0', sizeof(Node*)*(2*(i+1)+1));
        }
        
        *(tree+0) = NULL;
    }

    printf("%s: End \n", __func__);
    return arg;
}