#ifndef NOF
#define NOF 18
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
extern void* deleteMenu(void*);
extern void* deleteBeg(void*);
extern void* deleteEnd(void*);
extern void* deleteKey(void*);
extern void* deleteNth(void*);

extern void* (*fptr[NOF])(void*);