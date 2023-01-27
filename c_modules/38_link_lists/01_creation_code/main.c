#include"headers.h"
#include"structure.h"
#include"declarations.h"

int main()
{
    Node *start;
    #ifdef DEBUG
        printf("%s: Begin\n",__func__);
    #endif
        start = NULL;
        init();
        while(1)
        {
            start = (Node*)(*fptr[0])((void*)start); // calling Main Menu Function
        }


    #ifdef DEBUG
        printf("%s: End\n", __func__);
    #endif
    return 0;
}