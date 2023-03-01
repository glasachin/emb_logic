/*
This file opens a file and duplicates its file descriptor
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main()
{
    char file_name[30] = "04_print_environ.c";
    int fd,new_fd;
    char ch;
    fd = open(file_name, O_RDWR);
    new_fd = dup(fd);
    printf("-------Reading file with duplicate FD--------");
    while(read(new_fd,&ch,1) != 0)
    {
        printf("%c",ch);
    }
    return 0;
}