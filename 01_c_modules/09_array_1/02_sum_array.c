#include<stdio.h>
int main()
{
    int ar1[10],ar2[10],sum[10];
    int i, n;
    printf("Number of elements in array (max 10): ");
    scanf("%d",&n);
    if(n > 10)
    {
        printf("Array can not hold more than 10 numbers.\nEnter Numbers Again.\n");
        return 0;
    }
    for(i = 0; i < n; i++)
    {
        printf("Enter %dth Element of Array 1: ",i);
        scanf("%d",&ar1[i]);
    }
    for(i = 0; i < n; i++)
    {
        printf("Enter %dth Element of Array 2: ",i);
        scanf("%d",&ar2[i]);
    }
    for(i = 0; i < n; i++)
    {
        printf("Sum of %d + %d = %d\n",ar1[i],ar2[i],ar1[i]+ar2[i]);
    }
    return 0;
}