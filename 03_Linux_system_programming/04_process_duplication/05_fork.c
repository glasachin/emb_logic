/*
This file creates a child process using fork
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void print_info()
{
    printf("--File Name: %s\n",__FILE__);
    printf("--Function Name: %s\n",__func__);
    printf("--PID: %d\n", getpid());
    printf("--PPID: %d\n",getppid());
}

int main()
{
    int pid;
    pid = fork();
    switch(pid)
    {
        case 0:
                printf("Running a child process.\n");
                print_info();
                break;
        default:
            printf("Running Parent process\n");
            print_info();
    }

    printf("out of switch:\n");
    return 0;
}