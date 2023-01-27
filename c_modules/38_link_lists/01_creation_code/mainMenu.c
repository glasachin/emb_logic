#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* mainMenu(void *arg)
{
    int i;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif

    printf("%s: __Manin Menu__\n", __func__);
    if(!arg)
        printf("%s: 1: Create Link List\n", __func__);
    else
    {
        printf("%s: 2: Insert Node\n", __func__);
        printf("%s: 3: Delete Node\n", __func__);
        printf("%s: 4: Display Linklist\n", __func__);
        printf("%s: 5: Sort Link List\n", __func__);
    }
    printf("%s: 0: Exit Program\n", __func__);
    printf("%s: Enter Your Choice\n", __func__);
    scanf("%d", &i);

    if(i == 0)
        (*fptr[i+1])((void*)"success"); //exit program

    else if((i == 1) && !arg)
        arg = (*fptr[i+1])(arg); //create Link List
    else if ((i > 1) && (i <= 5))
        (*fptr[i+1])(arg);

    #ifdef DEBUG
        printf("%s: End\n", __func__);
    #endif
    return arg;
}