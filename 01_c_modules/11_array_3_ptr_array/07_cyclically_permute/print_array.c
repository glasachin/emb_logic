#include"headers.h"

void print_array(int **arr, int n,int array_no)
{
    int i = 0;
    for(i = 0; i < n; i++)
    {
        printf("%d ", *(*(arr+array_no)+i));
    }
    printf("\n");
}