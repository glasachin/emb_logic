/*
    This file creates a FIFO
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
    int r;
    r = mkfifo("temp", 0777);
    if(r == 0)
    {
        printf("FIFO Created Successfully!\n");
    }
    return 0;
}
