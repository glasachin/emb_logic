#include<stdio.h>
int main()
{
    int i=0,j=0,n = 10;
    while(i < n)
    {
        j = 0;
        while(j<=i)
        {
            printf("%d",i+1);
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}