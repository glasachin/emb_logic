#include"headers.h"
void add_2_arrays(int** arr, int p1, int p2, int p3, int n)
{
    /* p1: array1 position
    p2: array2 position
    p3: array3 position
    n: array length*/

    int i;
    *(arr+p3) = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++)
    {
        *(*(arr+p3)+i) = *(*(arr+p1)+i) + *(*(arr+p2)+i);
    }
}