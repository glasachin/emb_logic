#include<stdio.h>

int print_natural(int);
int sum_natural(int);

int main()
{
    int n;
    printf("Enter the limit upto which you wanted to print numbers: ");
    scanf("%d",&n);
    printf("Natural numbers between 1 and %d are: ",n);
    print_natural(n);
    printf("\n");
    printf("Sum of 1 to %d is: %d\n",n,sum_natural(n));
    return 0;
}

int print_natural(int n)
{
    int temp;
    temp = n;
    if(n == 1)
    {
        printf("%d ",n);
        return 0;
    }
    temp -= 1;
    print_natural(temp);
    printf("%d ",n);

}

int sum_natural(int n)
{
    if(n == 1)
        return 1;
    return n+sum_natural(n-1);
}