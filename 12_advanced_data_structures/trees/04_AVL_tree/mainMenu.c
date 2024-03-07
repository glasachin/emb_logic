#include"headers.h"
#include"structures.h"
#include"declarations.h"

void* mainMenu(void *arg)
{
    Node* avlTree;
    int ch;
    printf("%s: Start\n", __func__);

    avlTree = (Node*)arg;
    
    printf("----------Main Menu--------------");
    if(!avlTree)
        printf("1: To Create AVL Tree.\n");
    printf("2: Insert Node\n");
    printf("3: Display AVL Tree\n");
    printf("4: Delete Node \n");
    printf("0: Exit \n");

    printf("Please Enter Your Choice...\n");
    scanf("%d", &ch);

    printf("%s: End\n", __func__);
    return (void*)avlTree;
}