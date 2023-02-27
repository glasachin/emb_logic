#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i = 0;
    printf("Process Id: %d and Parent Process Id: %d\n", getpid(), getppid());
    for(i = 0; i < argc; i++)
    {
        printf("parameter %d: %s\n", i, argv[i]);
    }
    return 0;
}