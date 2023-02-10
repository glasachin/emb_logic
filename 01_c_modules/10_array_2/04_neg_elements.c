#include<stdio.h>
#define N 5
int main()
{
    int a[N], i, neg;
    printf("Enter Array Elements positive or negative: \n");
    for(i = 0; i < N; i++ )
    {
        scanf("%d",&a[i]);
    }
    neg = 0;
    for(i = 0; i < N; i++)
    {
        if(a[i] < 0)
        {
            printf("Negative Number: %d\n",a[i]);
            neg++;
        }
            
    }
    printf("Total Negative Numbers are: %d\n",neg);
    return 0;
}