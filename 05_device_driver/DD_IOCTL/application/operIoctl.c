/**
 * This file do the IOCTL Operation
*/

#include"headers.h"
#include"declarations.h"

void* operIoctl(void *arg)
{
    int ret;
    char *fn;
    printf("%s: Begin \n", __func__);
    int choice;
    int data;
    // fd = open((char*)arg, O_WRONLY); // fd is already obtained in open file
    
    // if(fd == -1)
    // {
    //     perror("open");
    //     goto OUT;
    // }
    // printf("%s: File Opened Successfully for IO Control. fd: %d\n", __FILE__, fd);
    // ret = ioctl(fd, DEVRESET);
    // if(ret == -1)
    // {
    //     perror("ioctl");
    //     goto ERR;
    // }
    while(1)
    {
        printf("1: Devise Reset\n");
        printf("2: Get Device Register Size\n");
        printf("3: Get Number of Registers\n");
        printf("4: Get Device Size\n");
        printf("5: Get Data Size\n");
        printf("6: set Device Register Size\n");
        printf("7: set Number of Registers\n");
        printf("8: set Device Size\n");
        printf("9: set Data Size\n");
        printf("0: Exit IOCTL Operations\n");
        scanf("%d", &choice);
        switch(choice)
        {
            case 0:
                goto OUT;
            case 1:
                ret = ioctl(fd, DEVRESET);
                if(ret == -1)
                {
                    perror("ioctl");
                    goto ERR;
                }
                break;
            case 2:
                ret = ioctl(fd, GETREGSIZE, &data);
                if(ret == -1)
                {
                    perror("ioctl");
                    goto ERR;
                }
                printf("%s: Device Register Size is %d\n", __func__, data);
                break;
            case 3:
                ret = ioctl(fd, GETNOOFREG, &data);
                if(ret == -1)
                {
                    perror("ioctl");
                    goto ERR;
                }
                printf("%s: Number of Registers in Device are %d\n", __func__, data);
                break;
            case 4:
                ret = ioctl(fd, GETDEVICESIZE, &data);
                if(ret == -1)
                {
                    perror("ioctl");
                    goto ERR;
                }
                printf("%s: Device Size is %d\n", __func__, data);
                break;
            case 5:
                ret = ioctl(fd, GETDATASIZE, &data);
                if(ret == -1)
                {
                    perror("ioctl");
                    goto ERR;
                }
                printf("%s: Data Size is %d\n", __func__, data);
                break;
            default:
                break;
        }

    }
ERR:
    printf("%s: End\n", __func__);
    sem_post(&sem);
    close(fd);
    return 0;
OUT:
    printf("%s: End\n", __func__);
    close(fd);
    sem_post(&sem);
    return 0;
}