/**
 * This file do the IOCTL Operation
*/

#include"headers.h"
#include"declarations.h"

void* operIoctl(void *arg)
{
    int ret;
    char *fn;
    printf("%s: Begin \n", __func__);
    
    // fd = open((char*)arg, O_WRONLY);
    
    if(fd == -1)
    {
        perror("open");
        goto OUT;
    }
    printf("%s: File Opened Successfully for IO Control. fd: %d\n", __FILE__, fd);
    ret = ioctl(fd, DEVRESET);
    if(ret == -1)
    {
        perror("ioctl");
        goto ERR;
    }

ERR:
    printf("%s: End\n", __func__);
    close(fd);
    return 0;
OUT:
    printf("%s: End\n", __func__);
    return 0;
}