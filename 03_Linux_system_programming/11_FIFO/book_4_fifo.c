/*
    This file tries to read from the FIFO file
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

#define FIFO_NAME "SACHIN"
#define BUF_SIZE 40

int main()
{
    int res;
    int fifo_fd;
    int open_mode = O_RDONLY;
    char buffer[BUF_SIZE+1];
    int msg_read = 0;

    memset(buffer,'\0', sizeof(buffer));

    /*-------Opening FIFO-----------*/
    printf("Process %d Opening FIFO O_RDONLY\n", getpid());
    fifo_fd = open(FIFO_NAME, open_mode);
    printf("Process %d result %d\n", getpid(), fifo_fd);

    /*-----Reading Data from FIFO------------*/
    if(fifo_fd != -1)
    {
        while(msg_read < 10)
        {
            res = read(fifo_fd, buffer, BUF_SIZE);
            msg_read += 1;
            printf("Read data from FIFO: %s\n", buffer);
        }
        close(fifo_fd);
    }
    else
    {
        perror("FIFO Opne Error");
        exit(EXIT_FAILURE);
    }

    printf("Process %d Finished,\n", getpid());
    exit(EXIT_SUCCESS);

}