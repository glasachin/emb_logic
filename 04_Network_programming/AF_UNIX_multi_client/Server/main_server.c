#include "../common/headers.h"

sem_t sem;

int main()
{
    int sfd, cfd, ret, len;
    int server_len, client_len;
    struct sockaddr_un saf;
    struct sockaddr_un csaf;
    pthread_t tid;

    printf("%s:%s: Begin.\n", __FILE__, __func__);

    // Initialize Semaphore
    ret = sem_init(&sem, 0, 1);
    if(ret == -1)
    {
        perror("semaphore");
        exit(EXIT_FAILURE);
    }


    // create an unamed socket for the server
    sfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("%s: Socket Created. fd: %d\n", __func__, sfd);

    // Name the socket
    saf.sun_family = AF_UNIX;
    strcpy(saf.sun_path, "../server_socket");
    server_len = sizeof(struct sockaddr_un);
    ret = bind(sfd, (struct sockaddr *)&saf, server_len);
    if(ret == -1)
    {
        perror("bind");
        close(sfd);
        exit(EXIT_FAILURE);
    }
    printf("%s: bind() Successfull\n", __func__);
    // create a connection queue and wait for clients
    listen(sfd, 5);

    while(1)
    {
        sem_wait(&sem);
        // create a thread
        ret = pthread_create(&tid, 0, processRequest, (void*)&sfd);
        if(cfd == -1)
        {
            perror("thread");
            exit(EXIT_FAILURE);
        }

        // //Accept a connection
        // client_len = sizeof(struct sockaddr_un);
        // cfd = accept(sfd, (struct sockaddr*)&csaf, &client_len);
        // if(cfd == -1)
        // {
        //     perror("accept");
        //     exit(EXIT_FAILURE);
        // }
        // printf("%s: accept() successful, cfd:%d\n", __fund__, cfd);

        // // read and write to client on client_sockfd
        // read(client_sockfd, &ch, 1);
        // ch++;
        // write(client_sockfd, &ch, 1);
        // close(client_sockfd);
    }

    printf("%s:%s: End.\n", __FILE__, __func__);
    return 0;
}