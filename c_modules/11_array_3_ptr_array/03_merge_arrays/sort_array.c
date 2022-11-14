#include"headers.h"

void sort_array_descending(int *arr, int n)
{
    int i,j;
    int temp = 0;
    for(j = n; j > 0; j--)
    {    
        for(i = 0; i < j-1; i++)
        {
            if(*(arr+i) < *(arr+i+1))
            {
                temp = *(arr+i);
                *(arr+i) = *(arr+i+1);
                *(arr+i+1) = temp;
            }
        }
    }

}