#include<stdio.h>
#include<math.h>
int main()
{
    int r1, r2, p, i, j,nd,a,b,rn=0;
    printf("Enter lower bound and upper bound to search for Armstrong Numbers: \n");
    scanf("%d%d",&r1,&r2);
    for(i = r1; i <= r2; i++)
    {
        // in = a;
        a = i;
        nd = 0;
        rn = 0;
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
        
        a = i;
        while(a!=0)
        {
            b = a%10;
            a = a/10;
            rn = rn+round(pow(b,nd));
        }

        if(rn == i)
            printf("Armstrong number: %d\n", i);
    }
}