#include"headers.h"
#include"declarations.h"

void* mainMenu(void*);
void* exitApplication(void*);
void* openDev(void*);
void* releaseDev(void*);
void* writeDev(void*);
void* readDev(void*);
void* operIoctl(void*);

void* (*fptr[NOF])(void*);

sem_t sem;

int init()
{
    int res;
    printf("%s: begin.\n", __func__);
    fptr[0] = mainMenu;
    fptr[1] = exitApplication;
    fptr[2] = openDev;
    fptr[3] = releaseDev;
    fptr[4] = writeDev;
    fptr[5] = readDev;
    fptr[6] = operIoctl;
    
    res = sem_init(&sem, 0, 0);
    if(res != 0)
    {
        perror("Semaphore Initialization Failed\n");
        (*fptr[1])((void*)"failure");
    }
    printf("%s: End\n", __func__);
    return 0;
}