#include<stdio.h>
int main()
{
    int a,p,i,pn=1;
    printf("Enter any no: ");
    scanf("%d",&a);
    printf("Enter the power to copute: ");
    scanf("%d",&p);
    for(i = 0; i < p; i++)
    {
        pn = pn*a;
    }
    printf("%d to the power %d is %d\n",a,p,pn);
    return 0;
}