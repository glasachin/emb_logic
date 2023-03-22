/*
    This function writes data into MQ.
    
    => If we run the program n times then n messages with same type will be recorded in the message
    queue.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/msg.h>
#include<sys/ipc.h>
#include<string.h>

int main()
{
    int qid;
    int ret;
    struct
    {
        long msgtype;
        char msgtext[10];
    }wbuff;
    
    /*---Creae message Queue------*/
    printf("Begin: %s\n", __func__);
    printf("Creating Message Queue..\n");
    qid = msgget((key_t)10, IPC_CREAT|0666);
    if(qid == -1)
    {
        perror("Message Queue");
        exit(EXIT_FAILURE);
    }

    printf("Message Queue created successfully.\n");
    
    /*---Send Data to Message Queue--------*/
    strcpy(wbuff.msgtext, "Sachin\0");
    wbuff.msgtype = 12;

    if((msgsnd(qid, &wbuff, 7,0)) == -1)
    {
        perror("Message Send Failed");
        exit(EXIT_FAILURE);
    }
    printf("Message Sent Successfully.\n");
    system("ipcs");
    printf("End: %s\n", __func__);
    exit(0);
}