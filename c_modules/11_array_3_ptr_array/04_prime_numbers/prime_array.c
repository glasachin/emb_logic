#include"headers.h"

void find_prime(int *arr, int n, int **p_arr,int *pl)
{
    int i,j,p = 1;
    *pl = 0;
    *p_arr = (int*)malloc(sizeof(int)*n);

    for(i = 0; i < n; i++)
    {
        p = 1;
        for(j = 2; j <= *(arr+i)/2; j++)
        {
            if(*(arr+i)%2 == 0)
            {
                p = 0;
                break;
            }
        }
        if(p == 1)
        {
            *(*p_arr+*pl) = *(arr+i);
            *pl += 1;
        }
    }
    sort_array_ascending(*p_arr,*pl);
}