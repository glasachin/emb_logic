#include"headers.h"

void copy_array(int **arr, int n, int no1, int no2)
{
    int i;

    *(arr+no2) = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++)
    {
        *(*(arr+no2)+i) = *(*(arr+no1)+i);
    }
}

void cyc_array(int **arr, int n, int no)
{
    int i, temp;
    temp = *(*(arr+no)+0);
    for(i = 0; i < n-1; i++)
    {
        *(*(arr+no)+i) = *(*(arr+no)+i+1);
    }
    *(*(arr+no)+i) = temp;
}