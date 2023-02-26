#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* deleteMenu(void *arg)
{
    int i, choice;

    printf("%s __Delete Menu__\n", __func__);
    if(arg)
    {
        printf("%s: 1. Delete at Beginning\n",__func__);
        printf("%s: 2. Delete at End\n",__func__);
        printf("%s: 3. Delete at the key value\n",__func__);
        printf("%s: 4. Delete at Nth Location\n",__func__);
        printf("%s: Enter your choice: \n",__func__);
        scanf("%d", &choice);

        (*fptr[choice+13])(arg);
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
