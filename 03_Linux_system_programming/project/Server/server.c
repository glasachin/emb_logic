#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

int main()
{
    Infra *infra;
    int ret;
    pthread_t thid;
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif

    init();
    infra = (Infra*)(*fptr[1])(0); // Create Infra

    while(1)
    {
        //get semaphore
        sem_wait(&infra->tsem);
        // create thread
        ret = pthread_create(&thid, NULL, fptr[2], (void*)infra);
        if(ret == -1)
        {
            perror("pthread create");
            (*fptr[0])((void*)"Failure");
        }
    }

    #ifdef DEBUG
        printf("%s: END.\n", __func__);
    #endif
    
    return 0;
}
