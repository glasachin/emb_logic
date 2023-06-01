/*bind is used to give name to the socket*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

/*to report errors*/
static void bail(const char *on_what){
    perror(on_whtat);
    exit(1);
}

int main(int argc, char **argv, char **envp){

    int z;
    int sck_inet;
    struct sockaddr_in adr_inet;
    int len_inet;

    /*create an IPv4 Internet Socket*/

    return 0;
}