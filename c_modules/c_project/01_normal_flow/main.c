#include"headers.h"
#include"declarations.h"

int main()
{
    int choice;
    #ifdef DEBUG
        printf("Starting Function: %s\n", __func__);
    #endif

    mainMenu();


    return 0;
}