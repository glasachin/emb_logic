#include"headers.h"

void check_subset(int *arr1, int n1, int *arr2, int n2)
{
    int i, j;
    int temp = 0;
    int subset = 0;
    for(i = 0; i < n1; i++)
    {
        temp = 0;
        for(j = 0; j < n2; j++)
        {
            if(*(arr1+i+temp) == *(arr2+j))
            {
                temp += 1;
                continue;
            }
            else
                break;
        }
        if(temp == n2)
        {
            subset = 1;
            break;
        }
        if( (n1 - i) < n2)
        {
            subset = 0;
            break;
        }   
    }

    if(subset == 1)
    {
        printf("Entered Sub-set array is an Sub-set of Original Array\n");
    }
    else
    {            
        printf("Entered Sub-set array is not an Sub-set of Original Array\n");
    }   
}