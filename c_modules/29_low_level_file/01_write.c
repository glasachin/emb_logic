#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

void create_file(char *fn)
{
    int fd;
    fd = open(fn, O_CREAT, S_IREAD | S_IWRITE);
    // fd = open(fn, O_CREAT);
    if(fd == -1)
    {
        perror("File Opened Failed!");
        exit(EXIT_FAILURE);
    }
    printf("File created successfully!\n");
    close(fd);
}

int open_write_file(char *fn)
{
    int fd;
    fd = open(fn, O_WRONLY);
    if(fd == -1)
    {
        perror("File Opened Failed!");
        exit(EXIT_FAILURE);
    }
    printf("File opened to write successfully!\n");
    return fd;
}

void write_data(int fd, char *data)
{
    int wr_len;
    wr_len = write(fd, data, strlen(data));
    if(wr_len == strlen(data))
        printf("Write successfull!\n");
}

int open_read_file(char *fn)
{
    int fd;
    fd = open(fn, O_RDONLY);
    if(fd < 0)
    {
        perror("File Opened Failed!");
        exit(EXIT_FAILURE);
    }
    printf("File opened to read successfully!\n");
    return fd;
}

int read_data(int fd)
{
    char data[100];
    int read_len;
    int r_l;
    read_len = lseek(fd, 0L, SEEK_END);
    lseek(fd, 0L, SEEK_SET);
    r_l = read(fd,data,read_len);
    if(r_l != read_len)
    {
        perror("Read Error");
        exit(EXIT_FAILURE);
    }
    printf("%s",data);
    printf("\nRead Successfull!\n");
}

int main()
{
    char fn[]="test.txt";
    int fd;
    create_file(fn);
    fd = open_write_file(fn);
    write_data(fd,"Hi, This is Nidhi Sharma.\nThanks for inviting me.");
    close(fd);
    fd = open_read_file(fn);
    read_data(fd);
    close(fd);
    return 0;
}