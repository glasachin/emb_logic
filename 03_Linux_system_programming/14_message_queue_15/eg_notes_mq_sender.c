/*
    This is the sender program for message queue
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define PERMISSIONS 0777

struct messageBuffer
{
    long messageType;
    char data[1024];
};

struct messageBuffer object;
int msqid;
int len;
int string_status;
key_t key;

void sendMessage()
{
    while(fgets(object.data, sizeof object.data, stdin) != NULL)
    {
        len = strlen(object.data);
        if(object.data[len-1] == '\n')
            object.data[len-1]='\0';
        
        if(msgsnd(msqid, &object, len+1, 0) == -1)
        {
            perror("msgsend");
            exit(EXIT_FAILURE);
        }
        string_status = strcmp(object.data,"end");
        if(string_status == 0)
            break;
    }
    // deleting the message queue
    if(msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }
    printf("Message Queue is done with sending messages.\n");
}

int main()
{
    system("touch messagequeue.txt");
    if((key = ftok("messagequeue.txt", 'B')) == -1)
    {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    if((msqid = msgget(key, PERMISSIONS|IPC_CREAT)) == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    printf("Message queue is ready to send messages. \n");
    printf("Enter lines of text, enter \'end\' to quit:\n");
    object.messageType = 1;
    sendMessage();
    //deleting the created file
    system("rm messagequeue.txt");
    return 0;
}