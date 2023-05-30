#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<errno.h>

int main(int argc, char **argv)
{
    int z;
    int s[2];

    z = socketpair(AF_LOCAL, SOCK_STREAM, 0, s);
    if(z == -1)
    {
        fprintf(stderr, "%s:socketpair", strerror(errno));
        exit(1);
    }

    printf("s[0] = %d;\n",s[0]);
    printf("s[1] = %d;\n", s[1]);
    system("netstat --unix -p");
    return 0;
}