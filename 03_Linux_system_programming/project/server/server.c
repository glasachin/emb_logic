#include"../Common/headers.h"
#include"declarations.h"

int main()
{
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif

    #ifdef DEBUG
        printf("%s: END.\n", __func__);
    #endif
    
    return 0;
}