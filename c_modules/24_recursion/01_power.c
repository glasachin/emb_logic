#include<stdio.h>

int com_power(int*, int*);

int main()
{
    int n,p,r;
    printf("Enter any number: ");
    scanf("%d",&n);
    printf("Enter the power to be calculated: ");
    scanf("%d",&p);
    r = com_power(&n,&p);
    printf("Power of %d is %d\n",n,r);
    return 0;
}

int com_power(int *n,int *p)
{
    if(*p == 0)
        return 1;
    *p -= 1;
    return *n*com_power(n,p);
}