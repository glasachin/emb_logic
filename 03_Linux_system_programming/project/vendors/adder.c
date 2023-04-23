#include"../Common/headers.h"
#include"../Common/dataStructure.h"


int main(int argc, char *argv[])
{
    int pfd;
    Request r;
    int ret,fd;
    #ifdef DEBUG
        printf("%s:%s: Begin.\n",__FILE__, __func__);
    #endif

    if(argc != 2)
    {
        printf("Error: Pipe fd not received\n");
        return -1;
    }
    pfd = atoi(argv[1]);
    
    #ifdef DEBUG
        printf("%s:%s: Pipe fd: %d \n",__FILE__, __func__, pfd);
    #endif

    ret = read(pfd, &r, sizeof(Request));
    if(ret == -1)
    {
        perror("read");
        exit("FAILURE");
    }

    // 

    #ifdef DEBUG
        printf("%s: %s: Read Request %d Bytes.\n",__FILE__, __func__, ret);
    #endif

    #ifdef DEBUG
        printf("%s: %s: END.\n",__FILE__, __func__);
    #endif
    
    return 0;
}
