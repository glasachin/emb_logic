/*
    AF_UNIX Socket Example
*/
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/un.h>
#include<sys/stat.h>
#include<unistd.h>
#include<errno.h>

/*---functin to report error****/
static void bail(const char *on_what)
{
    perror(on_what);
    exit(1);
}

int main(int argc, char **argv, char **envp)
{
    int z;
    int sck_unix;
    struct sockaddr_un adr_unix;
    int len_unix;
    const char pth_unix[] = "/tmp/my_sock";

    /*--Create a AF_UNIX socket----*/
    sck_unix = socket(AF_UNIX, SOCK_STREAM, 0);
    if(sck_unix == -1)
    {
        bail("socket()");
    }

    /* Remove the pathname for the socket, in case it existed from a prior run. Ignore errors */
    unlink(pth_unix);

    /* Form an AF_UNIX Address */
    memset(&adr_unix, 0, sizeof(adr_unix));

    adr_unix.sun_family = AF_UNIX;

    strncpy(adr_unix.sun_path, pth_unix, sizeof(adr_unix.sun_path-1));

    len_unix = SUN_LEN(&adr_unix);

    adr_unix.sun_path[0] = '\0'; // Making first byte NULL

    /* Now bind the address to the socket */
    z = bind(sck_unix, (struct sockaddr *)&adr_unix, len_unix);

    if(z == -1)
        bail("bind()");
    
    /* Display all of our bound sockets */\
    system("netstat -pa -unix77:2>/dev/null | sed -n '/^Active UNIX/,/^Proto/p; /af_unix/p'");

    /* close and unlink our socket path */
    close(sck_unix);
    unlink(pth_unix);

    return 0;
}