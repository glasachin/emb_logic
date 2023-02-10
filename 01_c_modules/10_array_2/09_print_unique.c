#include<stdio.h>
#define N 10
int main()
{
    int a[N],i,j,u[N],u_n = 0,o[N],occ;
    printf("Enter %d element into an array: \n", N);
    for(i = 0; i < N; i++)
    {
        scanf("%d",&a[i]);
    }
    // find unique numbers
    j = 0;
    u[0] = a[0];
    u_n = 1; //no. of unique numbers
    for(i = 1; i < N; i++)
    {
        for(j = 0; j < u_n; j++)
        {
            if(a[i] == u[j])
                break;
        }
        if( j == u_n)
        {
            u[j] = a[i];
            u_n += 1;
        }
    }

    // display the values
    printf("Unique numbers are as follows: \n");
    for(i = 0; i < u_n; i++)
    {
        printf("%d ", u[i]);
    }
    printf("\n");
    return 0;
}