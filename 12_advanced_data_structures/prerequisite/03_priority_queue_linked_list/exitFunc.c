#include "headers.h"
#include "declarations.h"

void* exitFunc(void *arg)
{
    printf("%s: Begin \n", __func__);

    if(strncmp((char*)arg, "success", 7) == 0)
        exit(EXIT_SUCCESS);
    else if(strncmp((char*)arg, "failure", 7) == 0)
        exit(EXIT_FAILURE);


    printf("%s: End ", __func__);
    return 0;
}