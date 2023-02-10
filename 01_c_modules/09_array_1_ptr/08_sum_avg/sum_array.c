#include"headers.h"
int sum_array(int *arr, int n)
{
    int i = 0;
    int sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += *(arr+i);
    }
    return sum;
}