#include"../common/headers.h"
#define CLISOCK "client%dsocket"

int main()
{
    int fd, ret;
    int len;
    struct sockaddr_un saf;
    int result;
    char ch = 'B';
    
    printf("%s:%s: Begin.\n", __FILE__, __func__);

    // Create a socket for the client
    fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("%s: Socket Created. fd: %d\n", __func__, fd);

    // Name the socket ad address with the server
    saf.sun_family = AF_UNIX;
    strcpy(saf.sun_path, "./server_socket");
    len = sizeof(struct sockaddr_un);
    // connect socket to the server's socket;
    result = connect(fd, (struct sockaddr *)&saf, len);
    if(result == -1)
    {
        printf("oops: client1\n");
        perror("connect");
        exit(1);
    }
    
    ret = write(fd, &ch, 1);
    if(ret == -1)
    {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // read(fd, &ch, 1);
    printf("char from server = %c\n", ch);
    sleep(2);
    exit(0);
    
}