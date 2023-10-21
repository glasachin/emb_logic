#include"headers.h"
#include"declarations.h"

int fd = 0;

void* openDev(void *arg)
{
    char ch;
    printf("%s: Begin \n", __func__);
    
    // testing with opening simple file
    // fd = open("Makefile", O_RDONLY);
    // if(fd < 0)
    // {
    //     perror("Open Dev");
    //     (*fptr[1])((void*)"failure");
    // }

    // while(read(fd,&ch,1) != 0)
    // {
    //     printf("%c", ch);
    // }

    // opening device
    if(strncmp((char*)arg, "writing",7)==0)
    {
        fd = open("./mydev", O_WRONLY);
        (*fptr[4])(NULL);
    }
    else if (strncmp((char*)arg, "reading",7)==0)
    {
        fd = open("./mydev", O_RDONLY);
        (*fptr[5])(NULL);
    }
    else if(strncmp((char*)arg, "ioctl", 5) == 0)
    {
        fd = open("./mydev", O_WRONLY);
        (*fptr[6])(NULL);
    }
    if(fd < 0)
    {
        perror("Open Dev");
        (*fptr[1])((void*)"failure");
    }

    printf("%s: End\n", __func__);
    return 0;
}