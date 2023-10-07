#include"headers.h"
#include"declarations.h"

void* mainMenu(void *arg)
{
    int i, ret;
    pthread_t thid;
    printf("%s: begin.\n", __func__);
    printf("%s: Device Menu\n", __func__);
    printf("%s: 1. Open Device to Write\n", __func__);
    printf("%s: 2. Open Device to read\n", __func__);
    printf("%s: 3. Close Device\n", __func__);
    printf("%s: 0. Exit Application\n", __func__);
    scanf("%d", &i);

    if(i == 0)
    {
        ret = pthread_create(&thid, 0, fptr[1], (void*)"success"); // creating a thread for exit function
        if(ret == -1)
        {
            perror("pthread_create ");
            (*fptr[1])((void*)"failure"); // calling exit function when thread creation failed
        }
    }
    // if((i >= 1) && ( i <= 4))
    // {
    //     
    //     ret = pthread_create(&thid, 0, fptr[i+1], (void*)"reading"); // we can improve the functionality
    //     if(ret == -1)
    //     {
    //         perror("Pthread_create ");
    //         (*fptr[1])((void*)"failure");
    //     }   
    // }
    else if( i == 1)
    {
        ret = pthread_create(&thid, 0, fptr[2], (void*)"writing");
    }
    else if( i == 2)
    {
        ret = pthread_create(&thid, 0, fptr[2], (void*)"reading");
    }
    else if( i == 3)
    {
        ret = pthread_create(&thid, 0, fptr[3], (void*)"reading");
    }
    printf("%s: End\n", __func__);
    return 0;
}