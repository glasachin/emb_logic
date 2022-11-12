#include"headers.h"

int** get_ptr_array()
{
    int **arr;
    arr = (int**)malloc(sizeof(int*)*ARRAY_PTR);
    if(arr == NULL)
    {
        perror("Memory allocation failed\n");
        exit(0);
    }

    memset(arr,0,ARRAY_PTR);
    return arr;
}

void get_input_array(int **arr, int n)
{
    int i=0;
    *arr = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++)
    {
        scanf("%d",*(arr+0)+i);
    }
}