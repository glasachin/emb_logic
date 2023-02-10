#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* exit_program(void *status)
{
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    if(strncmp((char*) status, "success",7) == 0)
        exit(EXIT_SUCCESS);
    
    else if(strncmp((char*)status, "failure",7)==0)
        exit(EXIT_FAILURE);

    #ifdef DEBUG
        printf("%s: End\n", __func__);
    #endif
}