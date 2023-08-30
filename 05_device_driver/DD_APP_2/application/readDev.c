#include"headers.h"
#include"declarations.h"

// int fd = 0;

void* readDev(void *arg)
{
    char ch;
    printf("%s: Begin \n", __func__);
    
    // Do read() system call

    printf("%s: End\n", __func__);
    return 0;
}