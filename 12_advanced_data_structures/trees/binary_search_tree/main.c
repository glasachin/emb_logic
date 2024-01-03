#include"headers.h"
#include"structure.h"
#include"declarations.h"

int main()
{
    Node* tree;

    printf("%s: Init \n", __func__);

    init();

    while(1)
    {
        tree = (Node*)(*fptr[1])((void*)tree);
    }

    printf("%s: End\n", __func__);
    return 0;
}