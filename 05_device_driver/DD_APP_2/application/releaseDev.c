#include"headers.h"
#include"declarations.h"

void* releaseDev(void *arg)
{
    printf("%s: Begin \n", __func__);
    
    // closing the file with 'fd'
    if(fd > 0)
        close(fd);
    else 
        printf("No file to close\n");
        
    printf("%s: End\n", __func__);
    return 0;
}