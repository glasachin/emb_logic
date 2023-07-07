/* This file implements the AF_INET client with Connect */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

<<<<<<< HEAD
#define DEST_IP "192.168.1.38"
#define DEST_PORT 8008
=======
#define DEST_IP "192.168.1.50"
#define DEST_PORT 8004
>>>>>>> f94db741d9aca084dd98eaf56d638496373700cd

int main(int argc, char *argv[])
{
    int sockfd, cfd;
    /* will hold the destination addr */
    struct sockaddr_in dest_addr;
    char ch;
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
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    /*Zero the rest of the struct*/
    memset(&(dest_addr.sin_zero), 0, 8);
    cfd = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(struct sockaddr));
    if( cfd == -1)
    {
        perror("connect() error lol\n");
        exit(1);
    }
    else
        printf("connect() is OK...\n");
    
    //write some data to server
    ch = 'A';
    write(cfd, &ch, 1);
    // read data 
    read(cfd, &ch, 1);
    printf("Data from server: %c\n", ch);
    // while(1);
    return 0;
}