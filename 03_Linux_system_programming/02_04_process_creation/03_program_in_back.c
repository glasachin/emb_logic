#include<stdio.h>
#include<stdlib.h>

int main()
{
    printf("Start Program File: %s\n", __FILE__);
    system("gcc -o 01_prog 01_run_linux_cmd.c");
    printf("Running the exe: \n");
    system("./01_prog &");
    printf("Execution done\n");
    printf("END Program File: %s\n", __FILE__);
    return 0;
}