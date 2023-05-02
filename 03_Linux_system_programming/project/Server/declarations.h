#define NOF 4

int init(void);

extern void* exitProgram(void*);
extern void* createInfra(void*);
extern void* processRequest(void*);
extern void* readResult(void*);

extern void* (*fptr[NOF])(void*);
