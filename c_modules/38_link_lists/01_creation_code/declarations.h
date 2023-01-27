#ifndef NOF
#define NOF 4
#endif

int init();
extern void* mainMenu(void*);
extern void* exit_program(void*);
extern void* createLinkList(void*);
extern void* insertNode(void*);
extern void* deleteNode(void*);
// extern void* displayLinkLis(void*);
// extern void* sortLinkList(void*);
extern void* createNode(void*);

extern void* (*fptr[NOF])(void*);