#include "../common/headers.h"

void* processRequest(void *arg)
{
    int fd, cfd, ret, len;
    int client_len;
    struct sockaddr_un csaf;
    

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
    
    printf("%s:%s: End.\n", __FILE__, __func__);
    return 0;
}