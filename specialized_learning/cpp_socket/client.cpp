#include <iostream>
extern "C"
{   
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
}
#define DEST_IP "127.0.0.1"
#define DEST_PORT 8034


int main()
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
    // dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    /*Zero the rest of the struct*/
    // memset(&(dest_addr.sin_zero), 0, 8);
    cfd = connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if( cfd == -1)
    {
        perror("connect() error lol\n");
        exit(1);
    }
    else
        printf("connect() is OK...\n");
    
    // //write some data to server
    // ch = 'A';
    // write(cfd, &ch, 1);
    // // read data 
    // read(cfd, &ch, 1);
    std::string message = "Hello, Server!";
    while(message != "exit")
    {
        // enter message to send
        std::cout << "Enter message to send: ";
        std::getline(std::cin, message);
        // send message to server
        send(sockfd, message.c_str(), message.size(), 0);
        // write(sockfd, message.c_str(), message.size());
        // receive response from server
        char buffer[1024] = {0};
        int bytesReceived = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived > 0)
        {
            buffer[bytesReceived] = '\0';
            std::cout << "Data from server: " << buffer << std::endl;
        }
    }
    send(sockfd, message.c_str(), message.size(), 0);
    return 0;
}
