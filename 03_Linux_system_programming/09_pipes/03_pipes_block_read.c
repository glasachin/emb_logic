/*
    This file create a pipe and demonstrate the block on read by child process.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{
    int pid, arr[2];
    char ch;
    if(pipe(arr) == 0)
    {
        printf("Pipe opened successfully!\n");
        pid = fork();
        switch(pid)
        {
            case -1:
                perror("Fork failed");
                exit(EXIT_FAILURE);
            
            case 0:
                printf("Inside child. PID: %d\n", getpid());
                close(arr[1]); //close write descriptor
                printf("block on read.\n");
                read(arr[0], &ch, 1);
                printf("Read character; %c\n",ch);
                break;
            default:
                printf("Inside the parent. PID: %d\n", getpid());
                close(arr[0]); //closed read descriptor
                printf("");
                sleep(10);
                write(arr[1], "A", 1);
                printf("parent sleeping. \n");
                sleep(5);
        }
        printf("Closed Process: %d\n",getpid());
    }
}