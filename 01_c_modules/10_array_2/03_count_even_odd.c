#include<stdio.h>
int main()
{
    int ar1[10],ar2[10],ar3[10];
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
    even_count = 0;
    odd_count = 0;
    for(i = 0; i < n; i++)
    {
        if(ar1[i] % 2 == 0)
        {
            ar2[even_count] = ar1[i];
            even_count++;
        }
        else
        {
            ar3[odd_count] = ar1[i];
            odd_count++;
        }
    }
    printf("Entered Array is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",ar1[i]);
    }
    printf("\nEven Array: \n");
    for(i = 0; i < even_count; i++)
    {
        printf("%d ",ar2[i]);
    }
    printf("\nOdd Array: \n");
    for(i = 0; i < odd_count; i++)
    {
        printf("%d ",ar3[i]);
    }
    printf("\n");
    printf("Total Even Numbers: %d\n",even_count);
    printf("Total Odd numbers: %d\n",odd_count);
    return 0;
}