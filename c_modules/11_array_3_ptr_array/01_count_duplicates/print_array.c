#include"headers.h"

void print_array(int **arr, int n)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(*(arr+0)+i));
    }
    printf("\n");
}