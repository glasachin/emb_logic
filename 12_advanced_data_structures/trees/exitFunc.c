#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* exitFunc(void *arg)
{
    printf("%s: Begin\n", __func__);

    if(strncmp((char*)arg, "success", 7) == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);
    

    printf("%s: End \n", __func__);
    return arg;
}