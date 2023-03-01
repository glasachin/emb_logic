/*
This program closes the FD no. 1 and write into another file using printf.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd, new_fd;

    fd = open("./print_test.txt",  O_CREAT|O_RDWR);
    // new_fd = dup(fd); //duplicate the standard out file descriptor
    close(1); //close standard out FD
    dup2(fd, 1); //duplicating file FD to standard out FD
    printf("Hi, this is sachin sharma and we are\ntesting dup2() call.\n");
    close(fd);
    return 0;

}

