#include<stdio.h>
int main()
{
    int ar1[10],sum=0;
    int i, n;
    float avg;
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
    printf("Entered array is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",ar1[i]);
        sum += ar1[i];
    }
    avg = (float)sum/n;
    printf("\nSum and Average of arrya elements are %d and %0.2f respectively\n",sum,avg);
    
    return 0;
}