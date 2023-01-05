#include"headers.h"
#include"declarations.h"

int main()
{
    dis *d;
    #ifdef DEBUG
        printf("starting: %s\n", __func__);
    #endif
    d = getInput();
    convert_dis(d);
    display(d);
    return 0;
}