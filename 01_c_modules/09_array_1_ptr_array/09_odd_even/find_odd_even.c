#include"headers.h"

void find_odd_even(int **arr,int n,int *el, int *ol)
{
    /*arr: pointer array
    n: size of the input array at location 0*/
    int i,even_len = 0, odd_len = 0;
    /*initialize odd and even array with atleast one element*/
    *(arr+1) = (int*)malloc(sizeof(int)*1);
    *(arr+2) = (int*)malloc(sizeof(int)*1);
    for(i = 0; i < n; i++)
    {
        if(*(*(arr+0)+i) % 2 == 0 )
        {
            even_len += 1;
            add_even(arr,1,even_len,*(*(arr+0)+i));
        }
        else
        {
            odd_len += 1;
            add_odd(arr,2,odd_len, *(*(arr+0)+i));
        }
    }
    *el = even_len;
    *ol = odd_len;
}

void add_even(int** arr1, int p, int el, int eval)
{
    /* arr1: pointer array
    p: positin in which element needs to be added
    el: even length*/
    *(arr1+p) = realloc(*(arr1+p), sizeof(int)*el);
    *(*(arr1+p)+el -1 ) = eval;
}

void add_odd(int** arr1, int p, int ol, int oval)
{
    /* arr1: pointer array
    p: positin in which element needs to be added
    el: even length*/
    *(arr1+p) = realloc(*(arr1+p), sizeof(int)*ol);
    *(*(arr1+p)+ol-1 ) = oval;
}