#include"headers.h"

void check_subset(int *arr1, int n1, int *arr2, int n2)
{
    int i,j,temp=0;

    for(i = temp; i < n1; i++)
    {
        for(j = 0; j < n2; j++)
        {
            if(*(arr2+j) != *(arr1+i+j))
            {
                break;
            }
        }
        if(j == n2)
        {
            printf("2nd array is the subset of 1st array. \n");
            printf("Location of subset is %d \n",i);
            break;
        }
        if(i+n2 >= n1)
        {
            printf("2nd array is not the subset of 1st array \n");
            break;
        }
    }
}