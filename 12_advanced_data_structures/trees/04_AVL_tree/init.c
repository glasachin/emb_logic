#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* mainMenu(void*);
void* exitFunc(void*);
void* createNode(void*);
void* createTree(void*);
void* insertNode(void*);

void* (*fptr[NOF])(void*);

void init(void)
{
    printf("%s: Start\n", __func__);

    fptr[MAIN_MENU] = mainMenu;
    fptr[EXIT_PROG] = exitFunc;
    fptr[CREATE_NODE] = createNode;
    fptr[CREATE_TREE] = createTree;
    fptr[INSERT_NODE] = insertNode;

    printf("%s: End\n", __func__);
}