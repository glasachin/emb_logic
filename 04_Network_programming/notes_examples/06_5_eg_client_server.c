/*Client-server program using sockets*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<time.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/wait.h>

#ifndef SHUT_WR
#define SHUT_RD 0
#define SHUT_WR 1
#define SHUT_RDWR 2
#endif

int main(int argc, char **argv)
{
    int z;
    int s[2];
    char *msgp;
    int mlen;
    char buf[80];
    pid_t chpid;
    //_-------create socket pair----------
    z = socketpair(AF_LOCAL, SOCK_STREAM, 0, s);

    if(z == -1)
    {
        fprintf(stderr, "%s: socketpair(2)\n", strerror(errno));
        exit(1);
    }

    // fork the process
    if((chpid = fork()) == (pid_t)-1) 
    {
        fprintf(stderr, "%s: fork(2)\n", strerror(errno));
        exit(1);
    }
    else if(chpid == 0)
    {
        // this is the chile process (client)
        char rxbuf[80];
        printf("Parent PID is %ld\n", (long)getppid());
        close(s[0]);
        s[0] = -1;
        msgp = "%S %d-%b-%y %l:%M %p";
        mlen = strlen(msgp);
        printf("Child sending request '%s'\n",msgp);
        fflush(stdout);
        /* write request to server */
        z = write(s[1], msgp, mlen);
        if(z < 0)
        {
            fprintf(stderr, "%s: write(2)\n",strerror(errno));
            exit(1);
        }
        // we are shutting down the writing part of the socket only
        if(shutdown(s[1],SHUT_WR) == -1)
        {
            fprintf(stderr,"%s: shutdown (2)\n",strerror(errno));
            exit(1);
        }

        // Receive reply from the server
        z = read(s[1], rxbuf,sizeof rxbuf);
        if(z < 0)
        {
            fprintf(stderr,"%s: read(2)\n", strerror(errno));
            exit(1);
        }
        rxbuf[z] = 0;
        printf("Server returned '%s'\n", rxbuf);
        fflush(stdout);
        close(s[1]);

    }

    else{
        /*Parent Process*/
        int status;
        char txbuf[80];
        time_t td;
        printf("Child PID is %ld\n", (long)chpid);
        fflush(stdout);
        close(s[1]);
        s[1] = -1; // forget this descriptor

        // wait for request from the client
        z = read(s[0], buf,sizeof buf);
        if(z < 0)
        {
            fprintf(stderr,"%s: read(2)\n",strerror(errno));
            exit(1);
        }

        buf[z] = 0;
        time(&td); //get current time
        strftime(txbuf, sizeof txbuf, buf, localtime(&td));
        z = write(s[0], txbuf, strlen(txbuf));
        
        if(z < 0){
            fprintf(stderr, "%s: write(2)\n",strerror(errno));
            exit(1);
        }

        close(s[0]);

        /*wait for child process to exit*/
        waitpid(chpid,&status,0);
    }
    return 0;
}