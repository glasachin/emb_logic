#include"headers.h"
#include"declarations.h"

void* mainMenu(void *arg);
void* exitFunc(void *arg);
void* createPQueue(void *arg);
void* enQueue(void *arg);
void* deQueue(void *arg);
void* display(void *arg);

void* (*fptr[NOF])(void*);

int init()
{
    printf("%s: Begin.", __func__);

    fptr[0] = mainMenu;
    fptr[1] = exitFunc;
    fptr[2] = createPQueue;
    fptr[3] = enQueue;
    fptr[4] = deQueue;
    fptr[5] = display;

    printf("%s: End", __func__);
    return 0;
}