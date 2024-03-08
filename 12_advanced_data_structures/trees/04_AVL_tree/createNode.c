#include"headers.h"
#include"structures.h"
#include"declarations.h"

void* createNode(void *arg)
{
    Node* newNode;
    printf("%s: Start\n", __func__);

    newNode = (Node*)malloc(sizeof(Node));
    if(!newNode)
    {
        printf("%s: Error in allocating Memory for new Node\n", __func__);
        (*fptr[EXIT_PROG])((void*)"failure");
    }
    newNode->value = 0;
    newNode->BF = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    printf("%s: Enter Value in the new node: \n", __func__);
    scanf("%d", &newNode->value);

    printf("%s: End\n", __func__);
    return (void*)newNode;
}