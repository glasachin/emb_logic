#include"headers.h"
#include"declarations.h"

void* mainMenu(void*);
void* exitApplication(void*);
void* openDev(void*);
void* releaseDev(void*);

void* (*fptr[NOF])(void*);

int init()
{
    printf("%s: begin.\n", __func__);
    fptr[0] = mainMenu;
    fptr[1] = exitApplication;
    fptr[2] = openDev;
    fptr[3] = releaseDev;
    
    printf("%s: End\n", __func__);
    return 0;
}