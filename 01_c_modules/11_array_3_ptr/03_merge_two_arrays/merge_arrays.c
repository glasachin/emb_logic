#include"headers.h"

int* merge_array(int *arr1, int *arr2, int n)
{
    int i, j = 0;
    int *arr = (int*)malloc(sizeof(int)*2*n);
    for(i = 0; i < 2*n; i+=2)
    {
        *(arr+i) = *(arr1+j);
        *(arr+i+1) = *(arr2+j);
        j++;
    }
    sort_array_descending(arr,2*n);
    return arr;
}