#include<stdio.h>
int main()
{
    int a,b,lcm,i,gcd,large;
    printf("Enter any two numbers: \n");
    scanf("%d%d",&a,&b);
    //---Finding GCD First------
    if(a>b)
    {
        large = a;
    }
        
    else
    {
        large = b;
    }
    for(i = large/2; i>=1; i--)
    {
        if((a%i == 0) && (b%i == 0))
        {
            gcd = i;
            break;
        }
    }

    //---------Finding LCM
    lcm = (a*b)/gcd;
    printf("LCM of %d and %d is %d\n",a,b,lcm);
    return 0;

}