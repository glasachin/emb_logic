#include"headers.h"

void get2Darray(char **arr, int *row, int *col)
{
    int i;
    printf("Enter the number of rows: ");
    scanf("%d",row);
    printf("Enter the number of columns: ");
    scanf("%d",col);
    *arr = (char*)malloc(sizeof(char)*(*row)*(*col));
    if(arr == NULL)
    {
        perror("Memory allocation failed!n");
        exit(0);
    }
    memset(*arr,' ',(*row)*(*col)*sizeof(char));
}

void fill2Darray(char *arr, int *row, int *col)
{
    int i, j, temp = 4;
    int rs = 4; //rhombous size

    for(i = 0; i < *row; i++)
    {
        for(j = 0; j < temp; j++)
        {
            *(arr+(i*(*col))+j) = ' ';
        }
        for(j; j < (temp+rs); j++)
        {
            *(arr+(i*(*col))+j) = '*';
        }
        // for(j; j < (*col - temp - rs); j++)
        // {
        //     *(arr+(i*col)+j) = ' ';
        // }
        temp -= 1;
    }
}
