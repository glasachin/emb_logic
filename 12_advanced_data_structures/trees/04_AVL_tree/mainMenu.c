#include"headers.h"
#include"structures.h"
#include"declarations.h"

void* mainMenu(void *arg)
{
    Node* avlTree;
    int ch;
    printf("%s: Start\n", __func__);

    avlTree = (Node*)arg;
    
    printf("----------Main Menu--------------\n");
    if(!avlTree)
        printf("1: To Create AVL Tree.\n");
    printf("2: Insert Node\n");
    printf("3: Display AVL Tree\n");
    printf("4: Delete Node \n");
    printf("0: Exit \n");

    printf("Please Enter Your Choice...\n");
    scanf("%d", &ch);

    switch(ch)
    {
        case 0:
            (*fptr[EXIT_PROG])((void*)"success");
            break;
        case 1: 
            avlTree = (Node*)(*fptr[CREATE_TREE])((void*)avlTree);
            break;
        default:
            printf("%s: -------Wrong choice--------\n", __func__);
            
    }


    printf("%s: End\n", __func__);
    return (void*)avlTree;
}