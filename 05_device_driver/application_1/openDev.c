#include"headers.h"
#include"declarations.h"

int fd = 0;

void* openDev(void *arg)
{
    char ch;
    printf("%s: Begin \n", __func__);
    
    // testing with opening simple file
    fd = open("Makefile", O_RDONLY);
    if(fd < 0)
    {
        perror("Open Dev");
        (*fptr[1])((void*)"failure");
    }

    while(read(fd,&ch,1) != 0)
    {
        printf("%c", ch);
    }

    

    printf("%s: End\n", __func__);
    return 0;
}