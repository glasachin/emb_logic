#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,rn = 0,in,nd;
    printf("Enter any number: ");
    scanf("%d",&a);
    in = a;
    nd = 0;
    if(a != 0)
    {
        while(a!=0)
        {
            nd+=1;
            a=a/10;
        }
    }
    else
    {
        nd = 1;
    }
    
    a = in;
    while(a!=0)
    {
        b = a%10;
        a = a/10;
        rn = rn+round(pow(b,nd));
    }

    if(rn == in)
        printf("Entered number is armstrong number!\n");
    else
        printf("Entered number is not an armstrong number!\n");
    return 0;
}