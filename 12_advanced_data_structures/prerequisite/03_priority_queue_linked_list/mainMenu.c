#include "headers.h"
#include "declarations.h"

void* mainMenu(void *arg)
{
    int i;
    PQueue *pq;

    printf("%s: Begin \n", __func__);
    pq = (PQueue*)arg;
    printf("%s: ___MAIN MENU______\n", __func__);
    if(!pq)
        printf("%s: 1. Create Priority Queue\n", __func__);
    else
    {
        printf("%s: 2. EnQueue: Add into Priority Queue\n", __func__);
        printf("%s: 3. DeQueue: Add into Priority Queue\n", __func__);
        printf("%s: 4. Display the Queue\n", __func__);
    }
    
    printf("%s: 0. Exit Program\n", __func__);
    printf("%s: Please Enter Your choise: \n", __func__);
    scanf("%d", &i);
    
    if(i == 0)
        (*fptr[1])((void*)"success"); // exit program
    else if(i == 1)
        arg = (*fptr[i+1])(arg);
    else if(i >=2 || i<= 4)
        (*fptr[i+1])(arg);

    printf("%s: End ", __func__);
    return arg;
}