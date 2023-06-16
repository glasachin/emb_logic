#include "../common/headers.h"

int main()
{
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    // create an unamed socket for the server
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);

    // Name the socket
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "./server_socket");
    server_len = sizeof(struct sockaddr_un);
    bind(server_sockfd, (struct sockaddr *)&server_address, server_len);

    // create a connection queue and wait for clients
    listen(server_sockfd, 5);

    while(1)
    {
        char ch;
        printf("Server waiting\n");
        //Accept a connection
        client_len = sizeof(struct sockaddr_un);
        client_sockfd = accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);
        // read and write to client on client_sockfd
        read(client_sockfd, &ch, 1);
        ch++;
        write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }

}