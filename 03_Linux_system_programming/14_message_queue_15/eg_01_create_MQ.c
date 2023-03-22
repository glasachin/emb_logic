/*
    This file create the message queue.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>

int main()
{
    int qid;
    int ret;

    printf("Begin: %s\n", __func__);
    printf("Creating Message Queue..\n");
    qid = msgget((key_t)10, IPC_CREAT|0666);
    if(qid == -1)
    {
        perror("Message Queue");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue created successfully.\n");
    system("ipcs");
    printf("End: %s\n", __func__);
    exit(0);
}