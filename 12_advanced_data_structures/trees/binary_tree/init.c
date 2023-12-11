#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* exitFunc(void*);
void* mainMenu(void*);
void** createTree(void**);
void** insertNode(void**);
void* deleteNode(void*);
void* traverseTree(void*);
void* createNode(void*);

void* (*fnptr[NOF])(void*);
void** (*fptr[NOF])(void**);


int init()
{
    Node *root;
    printf("%s: Begin\n", __func__);

    fptr[0] = exitFunc;
    fptr[1] = mainMenu;
    fptr[2] = createTree;
    fptr[3] = insertNode;
    fptr[4] = deleteNode;
    fptr[5] = traverseTree;
    fptr[6] = createNode;



    printf("%s: End \n", __func__);
    return 0;
}