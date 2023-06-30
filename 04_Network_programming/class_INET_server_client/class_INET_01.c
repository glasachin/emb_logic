/* This is a INET server example*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

// #define DEST_IP "127.0.0.4"
// #define DEST_PORT 8034
#define MYPORT 7777
#define BACKLOG 10

int main()
{
    /*listen on sock_fd, new connection on new_fd*/
    int sockfd, new_fd;
    /*my address information, */
    struct sockaddr_in my_addr;
    /*remote addresss infor*/
    struct sockaddr_in their_addr;

    int sin_size;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        perror("sockfd");
        exit(1);
    }
    else
        printf("Socket is OK....");
    /*host byte order*/
    my_addr.sin_family = AF_INET;
    /*short, network byte order*/
    my_addr.sin_port = htons(MYPORT);
    /*auto-fill with my IP*/
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY); //i.e. it will accept from any address
    /*zero the rest of the struct*/
    memset(&(my_addr.sin_zero), 0, 8);
    if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("bind() error");
        exit(1);
    }
    else
        printf("bind() is done\nn");
    if(listen(sockfd, BACKLOG) == -1)
    {
        perror("listen() error");
        exit(1);
    }
    else
        printf("listen() ok\n");
    
    /*....to read the received data....*/
    sin_size = sizeof(struct sockaddr_in);
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
    if(new_fd = -1)
        perror("accept() error ");
    else
        printf("accept() is ok\n");
    sleep(5);
    close(new_fd);
    close(sockfd);
    return 0;

}