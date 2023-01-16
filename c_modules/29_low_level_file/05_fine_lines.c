#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

int open_file(char *fn)
{
    int fd;
    fd = open(fn, O_RDONLY);
    if(fd < 0)
    {
        perror("Read Unsuccessfull!");
        exit(EXIT_FAILURE);
    }
    return fd;
}

int read_lines(int fd)
{
    int n=0;
    char ch;
    while(read(fd,&ch,1) != 0)
    {
        if(ch == '\n')
        {
            n+=1;
        }
    }
    return n;
}

int main()
{
    int fd;
    int n;
    char fn[] = "03_example.txt";
    fd = open_file(fn);
    n = read_lines(fd);
    printf("There are %d lines in %s File.\n",n, fn);
    return 0;
}