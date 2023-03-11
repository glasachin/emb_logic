/*
This file is used for interprocess communication and this file write data to the fifo.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

#define FIFO_NMAE "./SACHIN"

int main()
{
    int fifo_fd;
    int res;
    int open_mode = O_WRONLY;
    int msg_written = 0;


    /*---Check FIFO if already exists-----*/
    if(access(FIFO_NMAE, F_OK) == -1)
    {
        res = mkfifo(FIFO_NMAE, 0777);
        if(res != 0)
        {
            perror("FIFO FAILURE");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        printf("FIFO already exists.\n");
    }

    /*------Open FIFO to Write some data to it-----*/
    printf("Process %d opening FIFO O_WRONLY \n", getpid());
    fifo_fd = open(FIFO_NMAE, open_mode);
    printf("Process %d, FIFO FD: %d\n",getpid(), fifo_fd);

    /*--------Write data is opened successfully----------*/
    if(fifo_fd != -1)
    {
        while(msg_written < 10)
        {
            res = write(fifo_fd, "Hi, This is Sachin\n", 20);
            if(res == -1)
            {
                perror("FIFO Write error\n");
                exit(EXIT_FAILURE);
            }
            msg_written += 1;
            sleep(5);
        }
        close(fifo_fd);
    }
    else
    {
        perror("FIFO Open Error");
        exit(EXIT_FAILURE);
    }

    printf("Process %d finished\n", getpid());
    exit(EXIT_SUCCESS);
}

