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
    memset(&adr_srvr, 0, sizeof(adr_srvr));
    adr_srvr.sin_family = AF_INET;
    adr_srvr.sin_port = htons(9090);
    adr_srvr.sin_addr.s_addr = inet_addr(srvr_addr);


    if(adr_srvr.sin_addr.s_addr == INADDR_NONE)
        bail("bad address.");

    len_inet = sizeof(adr_srvr);

    /* create a UDP socket to use */
    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s == -1)
    {
        bail("socket()");
    } 

    for(;;)
    {
        fputs("\nEnter format string: ", stdout);
        if(!fgets(dgram, sizeof(dgram), stdin))
            break;
        
        z = strlen(dgram);
        if(z > 0 && dgram[-z] == '\n')
            dgram[z] = 0;
        
        /* send format string to server */
        z = sendto(s, dgram, strlen(dgram), 0, (struct sockaddr *)&adr_srvr, len_inet);
        if(z < 0)
            bail("sendto(2)");

        /* test if we asked for a server shutdown */
        if(!strcasecmp(dgram, "QUIT"))
            break;
        
        /*wait for a response*/
        x = sizeof(adr);
        z = recvfrom(s, dgram, sizeof(dgram), 0, (struct sockaddr *)&adr, &x);
        if(z < 0)
        {
            bail("recvfrom(2)");
        }

        dgram[z] = 0;

        /*report result*/
        printf("Result from %s port %u: \n\t'%s'\n", inet_ntoa(adr.sin_addr), (unsigned)ntohs(adr.sin_port), dgram);

    }

    /* close socket and exit */
    close(s);
    putchar('\n');
    return 0;
}