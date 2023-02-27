#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Starting file: %s\n", __FILE__);
    printf("maximum number of process information is: \n");
    system("prlimit -u");
    printf("Ending file: %s\n", __FILE__);
}