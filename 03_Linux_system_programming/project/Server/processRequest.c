#include"../Common/headers.h"
#include"../Common/dataStructure.h"
#include"declarations.h"

void* processRequest(void *arg)
{
    char prfd[2];
    int fd, fret;
    Infra *infra;
    Request r;
    int ret;
    Result *res;
    #ifdef DEBUG
        printf("%s: Begin.\n", __func__);
    #endif

    infra = (Infra*)arg;
    fd = open(FIFONAME, O_RDONLY);
    if(fd == -1)
    {
        perror("open");
        (*fptr[0])((void*)"failure");
    }

    #ifdef DEBUG
        printf("%s: Request FIFO Opened. fd: %d\n",__func__, fd);
    #endif

    ret = read(fd, &r, sizeof(Request));
    if(ret == -1)
    {
        perror("read");
        (*fptr[0])((void*)"failure");
    }

    #ifdef DEBUG
        printf("%s: Read server bytes: %d\n",__func__, ret);
    #endif

    // release the semaphore
    sem_post(&infra->tsem);
    printf("Process Request Thread Semaphore released\n");

    // fork to run new operation
    fret = fork();
    switch(fret)
    {
        case -1:
            perror("fork");
            (*fptr[0])((void*)"fialure");
            break;
        case 0:
            sprintf(prfd,"%d",*(infra->pipe)+0);
            // added by me
            if(r.oper == '+')
            {
                printf("Calling Adder\n");
                execl("./adder","adder",prfd, NULL);
                printf("%s: Error: execl() failed\n", __func__, ret);
            }
            else if(r.oper == '-')
            {
                printf("Calling Subtractor\n");
                execl("./subtract","subtract",prfd, NULL);
                printf("%s: Error: execl() failed\n", __func__, ret);
            }
            else if(r.oper == '*')
            {
                printf("Calling Multiplier\n");
                execl("./multiply","multiply",prfd, NULL);
                printf("%s: Error: execl() failed\n", __func__, ret);
            }
            else if(r.oper == '/')
            {
                printf("Calling Divider\n");
                execl("./divide","divide",prfd, NULL);
                printf("%s: Error: execl() failed\n", __func__, ret);
            }
            else
            {
                printf("Wrong Choice\n");
                exit(EXIT_SUCCESS);
            }
                
            
        default:
            if(sem_wait((sem_t*)infra->smptr1) == -1)
            {
                printf("%s : %d: Error sem_wait fail\n",__func__,__LINE__);
                (*fptr[0])((void*)"failure");
            } 
            printf("Started the semaphore to process the request from vendor.\n");
            //use semaphore before writing into pipe
            ret = write(*(infra->pipe)+1,&r,sizeof(Request));
            if(ret == -1)
            {
                perror("read");
                (*fptr[0])((void*)"failure");
            }

            #ifdef DEBUG
                printf("%s:%s: Wrote Request %d Bytes \n", __FILE__,__func__, ret);
            #endif
            res = (Result *)infra->smptr;
            sleep(10); // just for test
            #ifdef DEBUG
                printf("%s:%s: Result  CPID: %d, Result: %0.2f\n", __FILE__,__func__, res->cpid, res->result);
            #endif

            ret = msgsnd(infra->mqKey, (void*)res, sizeof(float),0);
            if(ret == -1)
            {
                perror("Process request msgsnd");
                (*fptr[0])((void*)"failure");
            }
    }

    // close the opened FIFO fd
    close(fd);
    #ifdef DEBUG
        printf("%s: End.\n",__func__);
    #endif
    
    
    return 0;
}