#define NOF 6
int init();

extern void* mainMenu(void*);
extern void* exitApplication(void*);
extern void* openDev(void*);
extern void* releaseDev(void*);
extern void* writeDev(void*);
extern void* readDev(void*);

void* (*fptr[NOF])(void*);

extern int fd;