#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Running %s\n", __func__);
    printf("Displaying present working directory: \n");
    system("pwd");
    return 0;
}