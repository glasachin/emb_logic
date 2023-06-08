/*This is the client program to test the UDP based server program*/
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>

/*error reporting function*/
static void bail(const char *on_what)
{
    fputs(strerror(errno), stderr);
    fputs(": ", stderr);
    fputs(on_what, stderr);
    fputc('\n', stderr);
    exit(1);
}

int main(int argc, char **argv)
{
    int z, x;
    char *srvr_addr = NULL;
    struct sockaddr_in adr_srvr;
    struct sockaddr_in adr;
    int len_inet;
    int s;
    char dgram[512];

    if(argc >= 2)
    {
        srvr_addr = argv[1];
    }
    else{
        srvr_addr = "127.0.0.23";
    }

    /*create a UDP socket address*/
}