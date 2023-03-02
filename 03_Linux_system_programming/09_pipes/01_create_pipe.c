/*
This file creates a pipe and prints its file descriptors
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int arr[2];

    if(pipe(arr) != -1)
    {
        printf("Pipe is opened with read FD %d and write FD %d \n",arr[0],arr[1]);
    }
    return 0;
}