#include"headers.h"

int* merge_array(int *arr1, int n1, int *arr2,  int n2)
{
    int i, j = 0;
    int *arr = (int*)malloc(sizeof(int)*(n1+n2));
    for(i = 0; i < n1; i++)
    {
        *(arr+i) = *(arr1+i);
    }
    for(i = n1; i < (n1+n2); i++)
    {
        *(arr+i) = *(arr2+j);
        j++;
    }
    sort_array_descending(arr,(n1+n2));
    return arr;
}