#include"headers.h"
#include"structure.h"
#include"declarations.h"

void* mainMenu(void* arg)
{
    int choice;
    printf("%s: Begin\n", __func__);

    printf("*******Main Menu**********\n");
    printf("0: Exit the program\n");
    printf("1: Create Tree\n");
    printf("2: Insert Node\n");
    printf("3: Inorder Traversal\n");
    printf("4: Preorder Traversal\n");
    printf("5: Postorder Traversal\n");
    printf("6: Find the smallest element\n");
    printf("7: Find the Largest element\n");
    printf("8: Count the total number of nodes\n");
    printf("9: Count the total number of internal nodes\n");
    printf("10: Count the total number of external nodes\n");
    printf("11: Determine the height of the tree\n");
    printf("12: Find the mirror image of the tree\n");
    printf("13: Delete an element\n");
    printf("14: \n");
    
    printf("\nPlease choose your option\n");
    scanf("%d", &choice);

    switch(choice)
    {
        case 0:
            (*fptr[0])((void*)"Byeee...");
            break;
        case 1:
            // printf("Creating Tree\n");
            arg = (void*)(*fptr[2])((void*)arg);
            break;
        case 2:
            // printf("insert Node\n");
            arg = (void*)(*fptr[3])((void*)arg);
            break;
        case 3:
            arg = (void*)(*fptr[4])((void*)arg);
            break;
        case 4:
            arg = (void*)(*fptr[5])((void*)arg);
            break;
        case 6:
            // smallest node
            (void*)(*fptr[7])((void*)arg);
            break;
        case 7:
            // largest node
            (void*)(*fptr[8])((void*)arg);
            break;
        case 13:
            arg = (void*)(*fptr[14])((void*)arg);
        default:
            printf("Wrong Choice!!\n");
            break;
    }

    printf("%s: End\n", __func__);
    return (void*)arg;
}
