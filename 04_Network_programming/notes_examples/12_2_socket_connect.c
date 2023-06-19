/* This file implements the AF_INET socket with Connect */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define DEST_IP "127.0.0.1"
#define DEST_PORT 80

int main(int argc, char *argv[])
{
    int sockfd;
    /* will hold the destination addr */
    struct sockaddr_in dest_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("Client-socket() error lol!");
        exit(1);
    }
    else
        printf("Client-socket() sockfd is OK...\n");
    
    /*host byte order*/
    dest_addr.sin_family = AF_INET;
    /*short, network byte order*/
    dest_addr.sin_port = htons(DEST_PORT);
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    /*Zero the rest of the struct*/
    memset(&(dest_addr.sin_zero), 0, 8);
    if(connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("Client-connect() error lol\n");
        exit(1);
    }
    else
        printf("Client-connect() is OK...\n");
    
    return 0;
}