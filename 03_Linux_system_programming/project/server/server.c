#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

int main()
{
    Infra *infra;
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif

    init();
    infra = (Infra*)(*fptr[1])(0); // Create Infra


    #ifdef DEBUG
        printf("%s: END.\n", __func__);
    #endif
    
    return 0;
}
