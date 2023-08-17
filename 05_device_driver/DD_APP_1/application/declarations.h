#define NOF 4
int init();

extern void* mainMenu(void*);
extern void* exitApplication(void*);
extern void* openDev(void*);
extern void* releaseDev(void*);

void* (*fptr[NOF])(void*);

extern int fd;