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
    int i, j;

    for(i = 0; i < *row; i++)
    {
        for(j = 0; j <= i; j++)
        {
            *(arr+(i*(*col))+j) = '*';
        }
    }
}
