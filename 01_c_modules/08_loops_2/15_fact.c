#include<stdio.h>
int main()
{
    int fact=1,n;
    printf("Enter any Nubmer: ");
    scanf("%d",&n);
    while(n > 1)
    {
        fact *= n;
        n--;
    }
    printf("Factorial of %d is %d\n",n,fact);
    return 0;
}