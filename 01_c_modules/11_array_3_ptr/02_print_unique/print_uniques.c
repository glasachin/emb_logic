#include"headers.h"

void print_uniques(int *arr, int n)
{
    int i,j; 
    
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i == j)
                continue;

            if(*(arr+i) == *(arr+j))
            {
                break;
            }
        }
        if(j == n)
            printf("%d ",*(arr+i));

    }
    printf("\n");
}