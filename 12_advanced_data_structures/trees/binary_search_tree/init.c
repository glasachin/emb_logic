#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* exitFunc(void*);
void* mainMenu(void*);
void* createTree(void*);
void* insertNode(void*);
void* inOrderTraverse(void*);
void* preOrderTraverse(void*);
void* postOrderTraverse(void*);
void* findSmallest(void*);
void* findLargest(void*);

void* deleteNode(void*);

void* (*fptr[NOF])(void*);

void init(void)
{
    printf("%s: Init \n", __func__);

    fptr[0] = exitFunc;
    fptr[1] = mainMenu;
    fptr[2] = createTree;
    fptr[3] = insertNode;
    fptr[4] = inOrderTraverse;
    fptr[5] = preOrderTraverse;
    fptr[6] = preOrderTraverse;
    fptr[7] = findSmallest;
    fptr[8] = findLargest;

    fptr[14] = deleteNode;
    

    printf("%s: End\n", __func__);
    // return 0;
}