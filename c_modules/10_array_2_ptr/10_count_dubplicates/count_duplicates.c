#include"headers.h"

int* get_unique(int *arr,int n, int *ul)
{
    int i,*uarr,j;
    uarr = (int*)malloc(n*sizeof(int));
    *uarr = *arr;
    *ul += 1;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < *ul; j++)
        {
            if(*(arr+i) == *(uarr+j))
                break;
        }

        if(j == *ul)
        {
            *(uarr+j) = *(arr+i);
            *ul += 1;
        }
    }
    return uarr;
}

void print_duplicates(int *arr, int n, int *uarr, int ul)
{
    int i, j, td = 0, dc = 0;

    for(i = 0; i < ul; i++)
    {
        dc = 0;
        for(j = 0; j < n; j++)
        {
            if(*(uarr+i) == *(arr+j))
                dc++;
        }

        if(dc > 1)
        {
            td += dc - 1;
        }
    }

    printf("Total duplicate elements are %d\n", td);
}