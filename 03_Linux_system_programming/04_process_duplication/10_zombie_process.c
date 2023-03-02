/*
    This program demonstrate the zombie process.
    run $ps -ax to see the child process in zombie state
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pid;
    pid = fork();
    switch(pid)
    {
        case -1:
            perror("Error");
            exit(EXIT_FAILURE);
        case 0:
            printf("Child Process.\n");
            break;
        default:
            printf("Parent Process\n");
            sleep(10);
    }
    printf("End PID: %d\n",getpid());
    return 0;
}