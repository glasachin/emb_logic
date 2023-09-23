#include"headers.h"
#include"declarations.h"

// int fd = 0;

void* readDev(void *arg)
{
    char ch;
    char ch1[15];
    int n;
    printf("%s: Begin \n", __func__);
    
    // Do read() system call
    // ch = 'K';
    // ch = 'K';
    // write(fd, &ch, sizeof(ch)); // we need to first write something
    
    n = read(fd, ch1, sizeof(ch1));

    printf("%s: Read device: %d, data: %s\n", __func__, n, ch1);

    printf("%s: End\n", __func__);
    return 0;
}