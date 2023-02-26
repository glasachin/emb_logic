#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* mainMenu(void*);
void* exit_program(void*);
void* createLinkList(void*);
void* createNode(void*);
void* insertNode(void*);
void* deletenode(void*);
void* displayLinkList(void*);
void* sortLinkList(void*);
void* insertMenu(void*);
void* insertBeg(void*);
void* insertEnd(void*);
void* insertKey(void*);
void* insertNth(void*);
void* deleteMenu(void*);
void* deleteBeg(void*);
void* deleteEnd(void*);
void* deleteKey(void*);
void* deleteNth(void*);


void* (*fptr[NOF])(void*);

int init()
{
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    fptr[0] = mainMenu;
    fptr[1] = exit_program;
    fptr[2] = createLinkList;
    fptr[3] = insertNode; 
    fptr[4] = deleteNode;
    fptr[5] = displayLinkList;
    fptr[6] = sortLinkList;
    fptr[7] = createNode;
    fptr[8] = insertMenu;
    fptr[9] = insertBeg;
    fptr[10] = insertEnd;
    fptr[11] = insertKey;
    fptr[12] = insertNth;
    fptr[13] = deleteMenu;
    fptr[14] = deleteBeg;
    fptr[15] = deleteEnd;
    fptr[16] = deleteKey;
    fptr[17] = deleteNth;

    #ifdef DEBUG
        printf("%s: End\n", __func__);
    #endif
    return 0;
}