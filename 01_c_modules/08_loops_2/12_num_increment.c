#include<stdio.h>
int main()
{
    int i=0,j=0,n = 10,k=1;
    while(i < n)
    {
        j = 0;
        while(j<=i)
        {
            printf("%2d ",k);
            j++;
            k++;
        }
        printf("\n");
        i++;
    }
    return 0;
}