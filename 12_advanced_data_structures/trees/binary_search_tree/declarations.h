#define NOF 14

extern void* exitFunc(void*);
extern void* mainMenu(void*);
extern void* createTree(void*);
extern void* insertNode(void*);
extern void* inOrderTraverse(void*);
extern void* preOrderTraverse(void*);
extern void* postOrderTraverse(void*);
extern void* findSmallest(void*);

void init(void);
extern void* (*fptr[NOF])(void*);