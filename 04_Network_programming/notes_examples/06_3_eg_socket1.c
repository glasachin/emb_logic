/* This file create socket descriptors and write/read data from them*/

#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<fcntl.h>
#include<errno.h>

int main(int argc, char **argv)
{
    int s[2]; // to stor the socket FD
    int z;
    char *cp;
    char buf[80];

    z = socketpair(AF_LOCAL, SOCK_STREAM, 0, s);
    if(z == -1)
    {
        // printf("error socket: %s\n", stderror(errno));
        exit(1);
    }

    //write on 2nd socket
    z = write(s[1], cp = "Hello?", 6);
    if(z < 0)
    {
        // fprintf(stderr, "%s:write", stderror(errno));
        return 2;
    }

    printf("Wrote message '%s' on s[1]\n",cp);

    z = read(s[0], buf, sizeof buf);
    buf[z] = '\0';
    printf("Received message '%s' for socket s[0]\n",buf);

    z = write(s[0], cp="Go away!", 8);
    
    z = read(s[1],buf, sizeof buf);
    buf[z] = '\0';
    printf("Received message '%s' from socket s[1] \n",buf);

    close(s[0]);
    close(s[1]);
    puts("Done");
    return 0;

}