#include"headers.h"
#include"declarations.h"

void* exitApplication(void *arg)
{
    printf("%s: Begin \n", __func__);
    if(strncmp((char*)arg, "success", 7) == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);
    return 0;
}