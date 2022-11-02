#include<stdio.h>
int main()
{
    int a[5],i,n=4,temp,j=0;
    printf("Enter array Elements: \n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Entered array is: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    j = n;
    for(i = 0; i<n/2; i++)
    {
        temp = a[j-1];
        a[j-1] = a[i];
        a[i] = temp;
        j -= 1;
    }
    printf("Reversed array is: ");
    for(i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;

}