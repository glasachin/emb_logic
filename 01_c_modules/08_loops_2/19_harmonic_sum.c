#include<stdio.h>
int main()
{
    int i=1, n;
    float sum;
    printf("Enter No. of Terms: ");
    scanf("%d",&n);
    while(i<=n)
    {
        sum += 1.0/i;
        i++;
    }
    printf("Sum of %d Terms is: %f",n,sum);
    return 0;
}