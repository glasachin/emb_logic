/*
    This program sends the messages in message queue of different types
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/msg.h>

struct block
{
    long int type;
    char msg[100];
};

int main()
{
    int i = 0;
    struct block msg_buf;
    long int msgid;
    char msg[100];

    //---create message queue-----
    if(msgget((key_t)10, IPC_CREAT|0666) == -1)
    {
        perror("msgget");
        exit(EXIT_FAILURE);
    }
    printf("Message Queue Created Successfully!");

    //send messages with different msgids
    for(i = 0; i < 10; i++)
    {
        msg_buf.type = i;
        strcpy(msg_buf.msg, strcat("Message Number: ", itoa(i)));
        msgsend();
    }

}

