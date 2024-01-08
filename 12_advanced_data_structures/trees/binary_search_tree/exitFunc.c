#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* exitFunc(void* arg)
{
    printf("%s: Init \n", __func__);

    if(strncmp((char*)arg, "success", 7) == 0)
        exit(EXIT_SUCCESS);
    else
        exit(EXIT_FAILURE);

    printf("%s: End\n", __func__);
    return (void*)arg;
}