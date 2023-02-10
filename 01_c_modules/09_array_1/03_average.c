#include<stdio.h>
int main()
{
    int n = 5, i;
    float avg = 0.0;
    int a[10];
    for(i = 0; i < n; i++)
    {
        printf("Enter an element: ");
        scanf("%d",&a[i]);
    }
    for(i = 0; i < n; i++)
    {
        avg += (float)a[i];
    }
    avg = (float)avg/n;
    printf("Average of Numbers is: %d",avg);
    return 0;
}