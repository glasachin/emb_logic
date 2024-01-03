#define NOF 4

extern void* exitFunc(void*);
extern void* mainMenu(void*);
extern void* createTree(void*);
extern void* insertNode(void*);

void init(void);
extern void* (*fptr[NOF])(void*);