#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Start Program File: %s\n", __FILE__);
    printf("Running %s\n", __func__);
    printf("Displaying present working directory: \n");
    system("pwd");
    printf("END Program File: %s\n", __FILE__);
    return 0;
}