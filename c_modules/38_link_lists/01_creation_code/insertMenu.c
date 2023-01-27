#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* insertMenu(void *arg)
{
    int i, choice;

    printf("%s __Insert Menu__\n", __func__);
    if(arg)
    {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert in between\n");
        scanf("%d\n", &choice);
        printf("You have entered %d\n");
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
