#ifndef __DECLARATIONS_H__
#define __DECLARATIONS_H__
#define NOF 5


extern void* mainMenu(void*);
extern void* exitFunc(void*);
extern void* createNode(void*);
extern void* createTree(void*);
extern void* insertNode(void*);


void init(void);

extern void* (*fptr[NOF])(void*);


#endif
