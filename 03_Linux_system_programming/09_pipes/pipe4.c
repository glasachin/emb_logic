/*
    This program gets executed by child process using execl program.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    int data_processed;
    char buffer[11];
    int fd;
    printf("Running process PID: %d, file: %s, PPID: %d\n", getpid(), __FILE__, getppid());
    memset(buffer, '\0', sizeof(buffer));
    sscanf(argv[1], "%d", &fd);
    data_processed = read(fd, buffer, 11);
    printf("%d: read %d bytes, %s\n", getpid(), data_processed, buffer);
    exit(EXIT_SUCCESS);
}