#include "../common/headers.h"

sem_t sem;

int main()
{
    int sfd, cfd, ret, len;
    int server_len, client_len;
    struct sockaddr_in saf;
    struct sockaddr_in csaf;
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
    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sfd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    printf("%s: Socket Created. fd: %d\n", __func__, sfd);

    // Name the socket
    saf.sin_family = AF_INET;
    saf.sin_port = htons(DEST_PORT);
    saf.sin_addr.s_addr = INADDR_ANY;
    memset(&(saf.sin_zero), 0, 8);
    // strcpy(saf.sun_path, "../server_socket");
    server_len = sizeof(struct sockaddr_in);
    ret = bind(sfd, (struct sockaddr *)&saf, server_len);
    if(ret == -1)
    {
        perror("bind");
        close(sfd);
        exit(EXIT_FAILURE);
    }
    printf("%s: bind() Successfull, Port: %d\n", __func__, DEST_PORT);
    
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

    }

    printf("%s:%s: End.\n", __FILE__, __func__);
    return 0;
}