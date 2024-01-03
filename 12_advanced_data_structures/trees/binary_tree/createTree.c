#include"headers.h"
#include"declarations.h"
#include"structures.h"

void** createTree(void **arg)
{
    Node **tree;
    int choice;
    printf("%s: Begin\n", __func__);

    tree = (Node**)arg;
    if(tree)
    {
        printf("%s: Three already Exists.\n", __func__);
        return arg;
    }
    
    // tree = (Node**)malloc(sizeof(Node*)*2);
    tree = (Node**)realloc(tree, sizeof(Node)*4); // we have created the 0th element as tree. at least of 2 to store the root.
    //used 4 in above to allocate space for Left and right child as well
    if(!tree)
    {
        perror("realloc");
        return arg;
    }

    memset(tree, '\0', sizeof(Node*)*4);
    // create Node (i.e. the root node)
    *(tree + 0) = NULL;
    *(tree + 1) = (Node*)(*fnptr[1])(0); // root node

    printf("%s: End \n", __func__);
    return (void**)tree;
}