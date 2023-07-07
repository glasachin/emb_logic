/* This is a INET server example*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>

// #define DEST_IP "192.168.1.38"
// #define DEST_PORT 8034
#define MYPORT 8008
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
    char ch;

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
    // my_addr.sin_addr.s_addr = htonl(INADDR_ANY); //i.e. it will accept from any address
    my_addr.sin_addr.s_addr = INADDR_ANY;
    /*zero the rest of the struct*/
    memset(&(my_addr.sin_zero), 0, 8);
    if(bind(sockfd, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
    {
        perror("bind() error");
        exit(1);
    }
    else
        printf("bind() is done\n");
    if(listen(sockfd, BACKLOG) == -1)
    {
        perror("listen() error");
        exit(1);
    }
    else
        printf("listen() ok\n");
    
    /*....to read the received data....*/
    sin_size = sizeof(struct sockaddr_in);
    while(1)
    {
        printf("Server waiting\n");
        new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size, 0);
        if(new_fd = -1)
        {
            perror("accept() error \n");
            fprintf(stdout, "%s: write(2)\n",strerror(errno));
            printf("%s: write(2)\n",strerror(errno));
            exit(EXIT_FAILURE);
        }
        else
            printf("accept() is ok\n");
        
        // read data
        printf("read data from client: \n");
        read(new_fd, &ch, 1);
        printf("data from client: %c\n",ch);
        ch++;
        // write back some data
        printf("sending back data to client: %c\n",ch);
        write(new_fd, &ch, 1);
        close(new_fd);
    }
    
    
    close(sockfd);
    return 0;

}