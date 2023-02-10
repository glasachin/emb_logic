#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    printf("Running %s, PID: %d, PPID: %d\n", __func__,getpid(), getppid());
    return 0;
}