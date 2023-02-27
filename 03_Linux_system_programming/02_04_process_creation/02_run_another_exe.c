#include<stdio.h>
#include<stdlib.h>

int main()
{
    system("gcc -o 01_prog 01_run_linux_cmd.c");
    printf("Running the exe: \n");
    system("./01_prog");
    printf("Execution done\n");
    return 0;
}