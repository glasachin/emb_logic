/*
    to see the impact run the code twice, one in forground and one in background.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

key_t keyk;

union semun
{
    int val; //value for SETVAL
    struct semid_ds *buf; //buffer of IPC_STAT, IPC_SET
    unsigned short *array; // array for GETALL, SETALL
    struct seminfo *__buf; //buffer for IPC_INFO (Linux specific)
};

union semun semunion[4];
struct sembuf sb;

int main()
{
    int i;
    sleep(1);
    keyk = semget((key_t)10, 4, 0666|IPC_CREAT);
    if(keyk == -1)
    {
        perror("semget");
        exit(EXIT_FAILURE);
    }
    system("ipcs");
    for(i = 0; i < 4; i++)
    {
        semunion[i].val = 1;
        if(semctl(keyk, i, SETVAL, semunion[i]) < 0)
            perror("semctl");
    }

    for(i = 0; i < 10; i++)
    {
        // entry region
        sb.sem_num = 0;
        sb.sem_op = -1; // wait operation
        sb.sem_flg = SEM_UNDO;
        if(semop(keyk, &sb, 1) == -1)
            perror("semop");

        // critical section
        printf("%d: %s: Running in the critical Region\n", getpid(), __func__);

        // exit region
        sb.sem_num = 0;
        sb.sem_op = 1; // signal operation
        sb.sem_flg = SEM_UNDO;
        if(semop(keyk, &sb, 1) == -1)
            perror("semop");
    }
    
    if(semctl(keyk, 1, IPC_RMID) < 0)
        printf("Error\n");
    // system("ipcs");
    return 0;
}
