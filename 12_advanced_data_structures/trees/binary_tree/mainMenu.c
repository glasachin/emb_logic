#include"headers.h"
#include"declarations.h"
#include"structures.h"

void* mainMenu(void *arg)
{
    Node *root;
    int choice;
    printf("%s: Begin\n", __func__);

    root = (Node*)arg;
    printf("%s: *********Main Menu**********\n", __func__);
    if(!root)
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
        (*fptr[0])((void*)"Success");
    }
    if(choice == 1)
        root = (Node*)(*fptr[choice+1])(0); // create tree
    else
        (*fptr[choice+1])((void*)root);


    printf("%s: End \n", __func__);
    return (void*)root;
}