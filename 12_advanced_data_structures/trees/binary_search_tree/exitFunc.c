#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* exitFunc(void* arg)
{
    printf("%s: Init \n", __func__);

    

    printf("%s: End\n", __func__);
    return (void*)arg;
}