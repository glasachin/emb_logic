#ifndef NOF
#define NOF 13
#endif

int init();
extern void* mainMenu(void*);
extern void* exit_program(void*);
extern void* createLinkList(void*);
extern void* insertNode(void*);
extern void* deleteNode(void*);
extern void* displayLinkList(void*);
extern void* sortLinkList(void*);
extern void* createNode(void*);
extern void* insertMenu(void*);
extern void* insertBeg(void*);
extern void* insertEnd(void*);
extern void* insertKey(void*);
extern void* insertNth(void*);

extern void* (*fptr[NOF])(void*);