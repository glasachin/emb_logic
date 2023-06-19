/* This file implements the AF_INET socket */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define MYPORT 3334

int main()
{
    int sockfd;
    struct sockaddr_in my_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("Server-socket() error lol!");
        exit(1);
    }
    else
        printf("Server-socket() sockfd is OK...\n");
    /* host byte order */
    my_addr.sin_family = AF_INET;
    /* short, network byete order */
    my_addr.sin_port = htons(MYPORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    /*zero the rest of the struct */
    memset(&(my_addr.sin_zero), 0, 8);
    if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("Server-bind() error lol!");
        exit(1);
    }
    else
        printf("Server-bind() is OK...\n");
    return 0;
}