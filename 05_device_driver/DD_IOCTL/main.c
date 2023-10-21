/**
 * We can create this file related functionality in Menu driver application as well.
*/
#include<stdio.h>
#include <string.h>
#include<fcntl.h>
#include"ioctl.h"
#include<sys/ioctl.h>

int main(int argc, char *argv[])
{
    int fd, ret;
    fd = open(argv[1], O_WRONLY); // file name of driver which we created using mknode
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
    close(fd);
    return 0;
OUT:
    return -1;

}