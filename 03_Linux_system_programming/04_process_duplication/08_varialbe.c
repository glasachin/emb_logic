/*
    This file do the fork and print the variable values and addresses both by the child and parent.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pid;
    int n = 10;
    pid = fork();
    switch(pid)
    {
        case -1:
            perror("for() Failed!");
            exit(EXIT_FAILURE);
        case 0:
            printf("Inside Child: \n");
            n = 15;
            printf("\tvalue of n is %d and address %d\n",n, &n);
            break;
        default:
            sleep(3);
            printf("Inside Parent: \n");
            printf("\t value of n is %d and address %d\n", n, &n);
            break;
    }
    return 0;
}