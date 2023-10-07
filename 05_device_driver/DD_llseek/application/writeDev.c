#include"headers.h"
#include"declarations.h"

// int fd = 0;

void* writeDev(void *arg)
{
    char ch;
    char ch1[80] = "Hello World! This is Sachin Sharm from JCBRO";
    char ch2[9] = "Kernel!";
    int n;
    printf("%s: Begin \n", __func__);
    
    // we are not holding the thread so direct reading will not work
    // printf("Which string want to write 1 or 2?\n");
    // scanf("%d", &n);
    n = 1;
    if( n == 1)
        write(fd, ch1, sizeof(ch1));
    else if(n == 2)
        write(fd, ch2, strlen(ch2)); // don't use strlen for empty string
    else
        write(fd, ch1, sizeof(ch1));

    printf("%s: End\n", __func__);
    return 0;
}