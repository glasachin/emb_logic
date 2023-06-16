#include"../common/headers.h"

int main()
{
    int sockfd;
    int len;
    struct sockaddr_un address;
    int result;
    char ch = 'A';
    // Create a socket for the client
    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    // Name the socket ad address with the server
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "./server_socket");
    len = sizeof(struct sockaddr_un);
    // connect socket to the server's socket;
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1)
    {
        printf("oops: client1\n");
        perror("connect");
        exit(1);
    }
    write(sockfd, &ch, 1);
    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    sleep(2);
    exit(0);
    
}