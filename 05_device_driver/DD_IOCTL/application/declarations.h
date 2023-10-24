#define NOF 7
int init();

extern void* mainMenu(void*);
extern void* exitApplication(void*);
extern void* openDev(void*);
extern void* releaseDev(void*);
extern void* writeDev(void*);
extern void* readDev(void*);
extern void* operIoctl(void*);

void* (*fptr[NOF])(void*);

extern int fd;
extern sem_t sem;