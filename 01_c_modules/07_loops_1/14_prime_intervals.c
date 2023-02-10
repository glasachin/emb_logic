#include<stdio.h>
int main()
{
    int r1, r2, p, i, j;
    printf("Enter lower bound and upper bound to search for Prime Numbers: \n");
    scanf("%d%d",&r1,&r2);
    for(i = r1; i <= r2; i++)
    {
        p = 1;
        for(j = 2; j <= i/2; j++)
        {
            if(i%j == 0)
            {
                p = 0;
                break;
            }
        }
        if(p == 1)
            printf("Prime Number: %d\n",i);
    }
}