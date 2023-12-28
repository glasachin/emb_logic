#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* exitFunc(void*);
void** mainMenu(void**);
void** createTree(void**);
void** insertNode(void**);
void** deleteNode(void**);
void** traverseTree(void**);
void* createNode(void*);

void* (*fnptr[NOF])(void*);
void** (*fptr[NOF])(void**);


int init()
{
    Node *root;
    printf("%s: Begin\n", __func__);

    fnptr[0] = exitFunc;
    fnptr[1] = createNode;
    
    fptr[0] = mainMenu;
    fptr[1] = createTree;
    fptr[2] = insertNode;
    fptr[3] = deleteNode;
    fptr[4] = traverseTree;
    



    printf("%s: End \n", __func__);
    return 0;
}