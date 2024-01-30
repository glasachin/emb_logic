#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* createTree(void* arg)
{
    printf("%s: Init \n", __func__);

    arg = NULL; // root node will be created in insert node function

    printf("%s: End\n", __func__);
    return (void*)arg;
}