#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* exitFunc(void*);
void* mainMenu(void*);
void* createTree(void*);
void* insertNode(void*);


void* (*fptr[NOF])(void*);

void init(void)
{
    printf("%s: Init \n", __func__);

    fptr[0] = exitFunc;
    fptr[1] = mainMenu;
    fptr[2] = createTree;
    fptr[3] = insertNode;
    

    printf("%s: End\n", __func__);
    // return 0;
}