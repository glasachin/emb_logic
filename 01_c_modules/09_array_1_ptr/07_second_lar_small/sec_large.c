#include"headers.h"
int second_largest(int *arr, int n)
{
    int i, sl, l;
    l = *arr;
    sl = l-1;
    for(i = 1; i < n; i++)
    {
        if(l < *(arr+i))
        {
            sl = l;
            l = *(arr+i);
        }

        if((*(arr+i) > sl) && (*(arr+i) < l))
        {
            sl = *(arr+i);
        }
    } 

    return sl;
}