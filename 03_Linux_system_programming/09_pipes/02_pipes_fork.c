/*
    This file creates a pipe and then create a child process using fork.
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int arr[2];
    int pid, pipe_status;

    pipe_status = pipe(arr);

    if(pipe_status == 0)
    {
        printf("Pipe is created successfully\n");
        
        pid = fork();
        if(pid == 0)
        {
            printf("In child process with PID as %d read FD as %d and write FD as %d.\n",getpid(),arr[0],arr[1]);
        }
        else if(pid > 0)
        {
            printf("In parent process with PID as %d read FD as %d and write FD as %d.\n",getpid(),arr[0],arr[1]);
        }
        else
        {
            printf("Fork is failed.\n");
        }
    }

    return 0;
}