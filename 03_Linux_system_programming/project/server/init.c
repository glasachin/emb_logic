#include "../Common/headers.h""
#include "declarations.h"

void* exitProgram(void*);
void* createInfra(void*);

void* (*fptr[NOF])(void*);


void init()
{
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif
    
    fptr[0] = exitProgram;
    fptr[1] = createInfra;


    #ifdef DEBUG
        printf("%s: END.\n", __func__);
    #endif
    
    return 0;
}
