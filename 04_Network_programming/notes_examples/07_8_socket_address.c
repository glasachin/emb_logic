/*This file uses the getpeername function*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

char * peer_addr(int s, char *buf, size_t bufsiz)
{
    int z;
    struct sockaddr_in adr_inet;
    int len_inet;

    len_inet = sizeof(adr_inet);
    z = getpeername(s,(struct sockaddr *)&adr_inet, &len_inet);

    if(z == -1)
    {
        return NULL;
    }

    z = snprintf(buf, bufsiz, "%s:%u", inet_ntoa(adr_inet.sin_addr),(unsigned)nthos(adr_inet.sin_port));
    if(z == -1)
    {
        return NULL;
    }

    return buf;
}

