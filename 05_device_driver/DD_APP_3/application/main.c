#include"headers.h"
#include"declarations.h"

int main()
{
    printf("%s: begin.\n", __func__);
    init();

    while(1)
    {
        (*fptr[0])(0); // Main Menu
    }

    printf("%s: End\n", __func__);
    return 0;
}