#include"headers.h"
#include"structures.h"
#include"declarations.h"

void* exitFunc(void *arg)
{

    printf("%s: Start\n", __func__);

    if(strcmp((char*)arg, "success") == 0)
    {
        printf("%s: Function ending successfully\n", __func__);
        exit(0);
    }
    else
    {
        exit(1);
    }

    printf("%s: End\n", __func__);
    return arg;
}