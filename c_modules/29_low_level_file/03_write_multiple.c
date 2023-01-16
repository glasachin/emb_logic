#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int open_create_file(char *fn)
{
    int fd;
    fd = open(fn, O_CREAT|O_WRONLY|O_RDONLY, S_IREAD|S_IWRITE);
    if(fd < 0)
    {
        perror("Error Opening File.\n");
        exit(EXIT_FAILURE);
    }
    return fd;
}

int write_data(int fd, char *data)
{
    int wr_len;
    // wr_len = write(fd, data, strlen(data));
    if(write(fd, data, strlen(data))!=strlen(data))
    // if(wr_len != strlen(data))
    {
        perror("Write Unsuccessfull!\n");
        return 1;
    }
    printf("Write Successfull!\n");
    return 0;
}


int main()
{
    int fd;
    char fn[] = "03_example.txt";
    // create_file(fn);
    fd = open_create_file(fn);
    write_data(fd, "Hi, This is First Line.\n");
    write_data(fd, "Hi, This is Second Line.\n");
    write_data(fd, "Hi, This is Third Line.\n");
    write_data(fd, "Hi, This is Fourth Line.\n");
    write_data(fd, "Hi, This is Sachin Sharma.\n");
    close(fd);
    return 0;    
}
