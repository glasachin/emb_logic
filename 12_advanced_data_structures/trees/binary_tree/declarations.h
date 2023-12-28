#define NOF 7

extern void* exitFunc(void*);
extern void** mainMenu(void**);
extern void** createTree(void**);
extern void** insertNode(void**);
extern void** deleteNode(void**);
extern void** traverseTree(void**);
extern void* createNode(void*);

int init(void);

extern void* (*fnptr[NOF])(void*);
extern void** (*fptr[NOF])(void**);