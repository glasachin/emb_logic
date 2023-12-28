#include"headers.h"
#include"declarations.h"
#include"structures.h"

/**
 * This will store the tree into an array.
*/
int main()
{
    Node **tree; // to store the array of pointer 
    printf("%s: Begin\n", __func__);
    
    init();

    tree = NULL;

    while(1)
    {
        tree = (Node**)(*fptr[0])((void**)tree);
    }


    printf("%s: End \n", __func__);
    return 0;
}