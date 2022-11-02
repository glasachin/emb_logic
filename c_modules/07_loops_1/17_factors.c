#include<stdio.h>
int main()
{
    int in, i, j;
    printf("Enter any Number: ");
    scanf("%d",&in);
    for(i = 1; i<=in; i++)
    {
        if(in%i == 0)
        {
            j = in/i;
            printf("%d x %d = %d\n",i,j,i*j);
        }
    }
}