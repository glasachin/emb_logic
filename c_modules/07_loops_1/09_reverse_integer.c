#include<stdio.h>
int main()
{
    int a,b,rn = 0;
    printf("Enter any number: ");
    scanf("%d",&a);
    while(a!=0)
    {
        b = a%10;
        a = a/10;
        rn = rn*10+b;
    }
    printf("Reverse number is %d\n",rn);
    return 0;
}