#include"headers.h"
int second_smallest(int *arr, int n)
{
    int i, ssm, sm;
    sm = *arr;
    ssm = sm+1;
    for(i = 1; i < n; i++)
    {
        if(sm > *(arr+i))
        {
            ssm = sm;
            sm = *(arr+i);
        }

        if((*(arr+i) < ssm) && (*(arr+i) > sm))
        {
            ssm = *(arr+i);
        }
    } 

    return ssm;
}