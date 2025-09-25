/*
    This file receives the messages send by the sender
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<errno.h>

#define PERMISSIONS 0777

struct messageBuffer
{
    long mtype;
    char data[1024];
};

struct messageBuffer object;
int msqid;
int string_status;
key_t key;

void receiveMessages()
{ int *msgLen, msg;
    msgLen = &msg;
    while(1)
    {
        *msgLen = msgrcv(msqid, &object, sizeof(object.data),0,0);
        // *msgLen = msgrcv(msqid, &object, sizeof(object.data),(long)0x00,IPC_NOWAIT);
        if( *msgLen == -1)
        // if(errno == ENOMSG)
        // if(msgrcv(msqid, &object, sizeof(object.data),0,0) == -1)
        {
            perror("msgrcv");
            exit(EXIT_FAILURE);
        }

        printf("Received: Id: %ld, Data:  \"%s\" , Len: %d\n", object.mtype, object.data, msg);
        string_status = strcmp(object.data,"end");
        if(string_status == 0)
            break;
    }
}

int main()
{
    if((key = ftok("/dev/mqueue/messagequeue.txt",'B')) == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if((msqid = msgget(key, PERMISSIONS)) == -1)
    {
        printf("Unable to create message queue");
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    printf("message queue is ready to receive messages.\n");
    receiveMessages();
    printf("Message queue is done receiving messages.\n");
    return(0);
}