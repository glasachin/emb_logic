#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter Number: ");
    scanf("%d",&n);
    for(i = 1; i <= 10; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("%2d x %2d = %2d, ",j,i,j*i);
        }
        printf("\n");
    }
    return 0;
}