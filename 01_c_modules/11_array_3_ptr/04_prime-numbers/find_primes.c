#include"headers.h"

void find_primes(int *arr, int n)
{
    int i, j, pl = 0;
    int cond = 0;
    int *p_arr = (int*)malloc(sizeof(int)*n);
    for(i = 0; i < n; i++)
    {
        cond = 1;
        for(j = 2; j <= *(arr+i)/2; j++)
        {
            if(*(arr+i)%j == 0)
            {
                cond = 0;
                break;
            }
        }

        if(cond == 1)
        {
            *(p_arr+pl) = *(arr+i);
            pl += 1;
        }
    }
    sort_array_ascending(p_arr, pl);
    print_array(p_arr, pl);
}