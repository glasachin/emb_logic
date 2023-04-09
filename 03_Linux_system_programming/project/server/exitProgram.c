#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

void* exitProgram(void *arg)
{
    #ifdef DEBUG
        printf("%s: Begin.\n",__func__);
    #endif


    
    
    #ifdef DEBUG
        printf("%s: End.\n", __func__);
    #endif
    return 0;
}
