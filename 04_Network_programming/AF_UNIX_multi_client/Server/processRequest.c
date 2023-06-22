#include "../common/headers.h"

void* processRequest(void *arg)
{
    int fd, cfd, ret, len;
    int client_len;
    struct sockaddr_un csaf;
    char ch;
    

    printf("%s:%s: Begin.\n", __FILE__, __func__);

    fd = *(int*)arg;

    //Accept a connection
    client_len = sizeof(struct sockaddr_un);
    cfd = accept(fd, (struct sockaddr*)&csaf, &client_len);
    if(cfd == -1)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("%s: accept() successful, cfd:%d\n", __func__, cfd);

    sem_post(&sem);
    
    // read and write to client on client_sockfd
    read(cfd, &ch, 1);
    // ch++;
    ch = toupper(ch);
    write(cfd, &ch, 1);


    printf("%s:%s: End.\n", __FILE__, __func__);
    return 0;
}