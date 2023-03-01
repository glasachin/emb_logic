/*
This file print the file name, PID and function name.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void print_info()
{
    printf("--File Name: %s\n",__FILE__);
    printf("--Function Name: %s\n",__func__);
    printf("--PID: %d\n", getpid());
}

int main()
{
    void (*fptr)(void);
    fptr = print_info;

    //------calling function------
    (*fptr)();

    return 0;
}