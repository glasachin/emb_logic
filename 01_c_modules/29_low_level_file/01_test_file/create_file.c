#include<headers.h>
#include<declarations.h>

int create_file(char *fn)
{
    int fd;
    fd = open(fn, O_CREAT, S_IREAD|S_IWRITE);
    return fd;
}