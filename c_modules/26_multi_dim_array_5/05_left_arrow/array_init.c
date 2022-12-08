#include"headers.h"

void get2Darray(char **arr, int *row, int *col)
{
    #ifdef DEBUG
        printf("Function: %s\n",__FUNC__);
    #endif
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
    int i, j,temp,dir;
    dir = 0;

    for(i = 0; i < *row; i++)
    {
        if(dir == 0)
        {
            temp = *row/2 - i;
            for(j = temp; j <= temp + (*row/2 - i); j++)
            {
                *(arr + i*(*col)+j) = '*';
            }
        }
        else
        {
            temp += 1;
            for(j = temp; j <= temp + (i - *row/2); j++)
            {
                *(arr + i*(*col)+j) = '*';
            }
            
        }
        
        if(temp == 0)
        {
            dir = 1;
            // temp = 1;
        }
    }
}
