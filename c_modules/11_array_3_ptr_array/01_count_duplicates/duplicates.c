#include"headers.h"

void count_duplicates(int **arr, int n)
{
    int i,j,ul = 0;
    // we are storing two arrays in **arr, 0th location: input array
    // 1st location: unique lements array
    // initialize 2nd array to store the unique numbers
    *(arr+1) = (int*)malloc(sizeof(int)*n);
    if(*(arr+1) == NULL)
    {
        perror("Memory allocation failed.\n");
        exit(0);
    }

    memset(*(arr+1), 0, n); //Initialize allocated memory space with 0

    *(*(arr+1)+ul) = *(*(arr+0)+0);
    ul += 1;
    for(i = 1; i < n; i++)
    {
        for(j = 0; j < ul; j++)
        {
            if(*(*(arr+0)+i) == *(*(arr+1)+j))
                break;
        }
        if(j == ul)
        {
            
        }
    }
}