#include "headers.h"
#include "declarations.h"

int exitProgram(char *status)
{
    #ifdef DEBUG
        printf("Running: %s\n",__func__);
    #endif
    
    if(strncmp(status, "success",7) == 0)
    {
        exit(EXIT_SUCCESS);
    }
    else if(strncmp(status,"failure",7)==0)
    {
        exit(EXIT_FAILURE);
    }

    #ifdef DEBUG
        printf("Function ends: %s\n",__func__);
    #endif

    return 0;
}