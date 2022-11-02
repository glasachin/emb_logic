#include<stdio.h>
int main()
{
    int i = 0,j = 0,n,sum = 0;
    printf("Enter Number: ");
    scanf("%d",&n);
    while(i < n)
    {
        if(j%2 != 0)
        {
            printf("%d ",j);
            sum += j;
            i++;
        }
        j++;
    }
    printf("\nSum of Odd numbers is: %d",sum);
    return 0;
}