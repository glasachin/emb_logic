#include<stdio.h>
int main()
{
    int ar1[10],ar2[10];
    int i, n, even_count, odd_count;
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
        ar2[i] = ar1[i];
    }
    printf("Copied Array is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",ar2[i]);
    }
    printf("\n");
    return 0;
}