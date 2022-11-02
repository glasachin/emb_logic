#include<stdio.h>
int main()
{
    int n = 5, i;
    int sum = 0;
    int a[10];
    printf("Executing %s\n",__func__);
    for(i = 0; i < n; i++)
    {
        printf("Enter an element: ");
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n; i++)
    {
        sum += a[i];
    }
    printf("Sum of Numbers is: %d",sum);
    return 0;
}