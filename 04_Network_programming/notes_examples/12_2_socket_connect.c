/* This file implements the AF_INET socket with Connect */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define DEST_IP "127.0.0.4"
#define DEST_PORT 8034

int main(int argc, char *argv[])
{
    int sockfd;
    /* will hold the destination addr */
    struct sockaddr_in dest_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("socket() error lol!");
        exit(1);
    }
    else
        printf("socket() sockfd is OK...\n");
    
    /*host byte order*/
    dest_addr.sin_family = AF_INET;
    /*short, network byte order*/
    dest_addr.sin_port = htons(DEST_PORT);
    dest_addr.sin_addr.s_addr = htonl(inet_addr(DEST_IP));
    /*Zero the rest of the struct*/
    memset(&(dest_addr.sin_zero), 0, 8);
    if(connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("connect() error lol\n");
        exit(1);
    }
    else
        printf("connect() is OK...\n");
    
    return 0;
}