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
    perror(on_what);
    exit(1);
}

int main(int argc, char **argv, char **envp){

    int z;
    int sck_inet;
    struct sockaddr_in adr_inet;
    int len_inet;

    /*create an IPv4 Internet Socket*/
    sck_inet = socket(AF_INET, SOCK_STREAM, 0);

    if(sck_inet == -1)
        bail("socket()");
    
    /*Create and AF_INET address*/
    memset(&adr_inet, 0, sizeof adr_inet);
    adr_inet.sin_family = AF_INET;
    adr_inet.sin_port = htons(9000);

    inet_aton("127.0.0.24", &adr_inet.sin_addr);

    len_inet = sizeof adr_inet;

    /*bind address to the socket*/
    z = bind(sck_inet, (struct sockaddr *)&adr_inet, len_inet);
    if(z == -1)
        bail("bind()");
    
    // system("netstat -pa --tcp 2 > /dev/null | sed -n '1,/^Proto/p;/bind/p'");

    close(sck_inet);

    return 0;
}