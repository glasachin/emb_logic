/*
    This file open a pipe and then do the fork.
    child process starts another process using execl command.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
    int fd, pid, arr[2];
    char buf[5];

    if(pipe(arr) == 0)
    {
        printf("Pipe opened successfully.\n");
        pid = fork();
        switch(pid)
        {
            case -1:
                perror("Fork Failed");
                exit(EXIT_FAILURE);
            case 0:
                printf("Chile created successfully. PID: %d\n", getpid());
                sprintf(buf,"%d",arr[0]);
                execl("pipe4","pipe4",buf, (char *)0);
            default:
                printf("Parent process, PID: %d\n", getpid());
                write(arr[1],"A", 1);
                printf("Written data.\n");
        }
        printf("End process, PID: %d\n", getpid());
    }
    exit(EXIT_SUCCESS);
}