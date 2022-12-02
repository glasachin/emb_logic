#include"headers.h"

void print2Darray(char *arr, int *row, int *col)
{
    int i,j;
    for(i = 0; i < *row; i++)
    {
        for(j = 0; j < *col; j++)
        {
            printf("%c",*(arr+(i*(*col))+j));
        }
        printf("\n");
    }
}