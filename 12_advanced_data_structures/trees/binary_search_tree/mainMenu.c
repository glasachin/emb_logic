#include"headers.h"
#include"structure.h"

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
    

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            printf("Creating Tree\n");
            break;
    }

    printf("%s: End\n", __func__);
    return (void*)arg;
}
