#include"headers.h"
#include"declarations.h"

// int fd = 0;

void* writeDev(void *arg)
{
    char ch;
    printf("%s: Begin \n", __func__);
    
    // Do write() system call
    ch = 'K';
    write(fd, &ch, sizeof(ch));

    printf("%s: End\n", __func__);
    return 0;
}