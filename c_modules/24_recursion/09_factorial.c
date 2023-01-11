#include<stdio.h>

int fact(int);

int main()
{
    int n,val;
    printf("Enter any number: ");
    scanf("%d",&n);
    printf("Factorial is: ");
    val = fact(n);
    printf("%d\n",val);
    return 0;
}

int fact(int n)
{
    if (n == 1)
        return 1;
    
    return n*fact(n-1);
}