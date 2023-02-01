#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* insertMenu(void *arg)
{
    int i, choice;

    printf("%s __Insert Menu__\n", __func__);
    if(arg)
    {
        printf("%s: 1. Insert at Beginning\n",__func__);
        printf("%s: 2. Insert at End\n",__func__);
        printf("%s: 3. Insert at the key value\n",__func__);
        printf("%s: 4. Insert at Nth Location\n",__func__);
        printf("%s: Enter your choice: \n",__func__);
        scanf("%d", &choice);

        (*fptr[choice+8])(arg);
        // switch(choice)
        // {
        //     case choice:
        // }
    }
    else
    {
        printf("Link List is not Created. First create it.\n");
    }
    return arg;
}
