#include<stdio.h>
int main()
{
    int a[10],i,n=10;
    printf("Enter %d Numbers into an array: \n",n);
    for(i = 0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    printf("Entered array is: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}