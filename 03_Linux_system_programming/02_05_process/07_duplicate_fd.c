/*
This file opens a file and duplicates its file descriptor
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char file_name[30] = "04_print_environ.c";
    int fd;

    fd = open(file_name, O_RDWR);
}