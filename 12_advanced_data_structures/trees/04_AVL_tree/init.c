#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* mainMenu(void*);

void* (*fptr[NOF])(void*);

void init(void)
{
    printf("%s: Start\n", __func__);

    fptr[0] = mainMenu;

    printf("%s: End\n", __func__);
}