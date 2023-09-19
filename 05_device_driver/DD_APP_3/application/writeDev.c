#include"headers.h"
#include"declarations.h"

// int fd = 0;

void* writeDev(void *arg)
{
    char ch;
    char ch1[15] = "Hello World!";
    printf("%s: Begin \n", __func__);
    
    // Do write() system call
    // ch = 'K';
    // write(fd, &ch, sizeof(ch));
    write(fd, ch1, sizeof(ch1));

    printf("%s: End\n", __func__);
    return 0;
}