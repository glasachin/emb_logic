/*
    This is the class example.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

key_t keyk;

int main()
{
    int i;
    sleep(5);
    keyk = semget((key_t)123, 4, 0666|IPC_CREAT);
    if(keyk == -1)
    {
        perror("semget");
        exit(EXIT_FAILURE);
    }
    system("ipcs");
    return(0);
}