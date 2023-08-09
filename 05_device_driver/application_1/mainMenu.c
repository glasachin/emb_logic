#include"headers.h"
#include"declarations.h"

void* mainMenu(void *arg)
{
    int i;
    printf("%s: begin.\n", __func__);
    printf("%s: Device Menu\n", __func__);
    printf("%s: 1. Open Device\n", __func__);
    printf("%s: 2. Close Device\n", __func__);
    printf("%s: 0. Exit Application\n", __func__);
    scanf("%d", &i);

    if(i == 0)
    {
        (*fptr[i+1])((void*)"success");
    }
    if((i >== 1) && ( i <= 2))
        (*fptr[i+1])(0);
    
    printf("%s: End\n", __func__);
    return 0;
}