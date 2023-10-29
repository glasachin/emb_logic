#define NOF 6

int init();
// PQueue* createNode();

extern void* mainMenu(void *arg);
extern void* exitFunc(void *arg);
extern void* createPQueue(void *arg);
extern void* enQueue(void *arg);
extern void* deQueue(void *arg);
extern void* display(void *arg);

extern void* (*fptr[NOF])(void*);

