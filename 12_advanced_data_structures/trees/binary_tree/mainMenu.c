#include"headers.h"
#include"declarations.h"
#include"structures.h"

void** mainMenu(void **arg)
{
    Node **tree;
    int choice;
    printf("%s: Begin\n", __func__);

    tree = (Node**)arg;
    printf("%s: *********Main Menu**********\n", __func__);
    if(!tree)
        printf("%s: 1: Create Tree\n", __func__);
    else
    {
        printf("%s: 2: Insert Node\n", __func__);
        printf("%s: 3: Delete Node\n", __func__);
        printf("%s: 4: Traverse Node\n", __func__);
        
    }
    printf("%s: 0: Exit Node\n", __func__);
    printf("%s: Enter Your Choice: \n",__func__);
    scanf("%d", &choice);

    if (choice == 0)
    {
        // exit
        (*fnptr[0])((void*)"Success");
    }
    if(choice == 1)
        tree = (Node**)(*fptr[1])((void**)tree); // create tree
    else
        tree = (Node**)(*fptr[choice])((void**)tree);


    printf("%s: End \n", __func__);
    return (void**)tree;
}