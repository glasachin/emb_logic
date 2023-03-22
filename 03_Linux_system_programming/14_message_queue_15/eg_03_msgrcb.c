/*
    This file reads the messages from the MQ. message were send by the 'msgsend.c' program
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

typedef struct 
{
    long msgtype;
    char msgtext[10];
}rbuff;

int main()
{
    int qid;
    int ret;
    rbuff rb;

    printf("Begin: %s\n", __func__);
    printf("Creating Message Queue..\n");
    qid = msgget((key_t)10, IPC_CREAT|0666);
    if(qid == -1)
    {
        perror("Message Queue");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue created successfully.\n");

    // Reading data from message queue
    if((msgrcv(qid, &rb, 7, 12, 0)) == -1) // same message type as was in the sender
    {
        perror("Message Read");
        exit(EXIT_FAILURE);
    }
    printf("Message received successfully.\n");
    printf("Received message: %s\n", rb.msgtext);
    
    system("ipcs");
    printf("End: %s\n", __func__);
    exit(0);
}