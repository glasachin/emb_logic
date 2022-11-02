#include<stdio.h>
int main()
{
    int a,b,lcm,i,large,small;
    printf("Enter any two numbers: \n");
    scanf("%d%d",&a,&b);
    if(a>b)
    {
        large = a;
        small = b;
    }
        
    else
    {
        large = b;
        small = a;
    }
    for(i = 1; i<=b; i ++)
    {
        if((large*i)%small == 0)
        {
            lcm = large*i;
            break;
        }
    }
    printf("LCM of %d and %d is %d\n",a,b,lcm);
    return 0;

}