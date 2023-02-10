#include<stdio.h>
#define N 8
int main()
{
    int ar[N+3] = {1,3,5,2,8,0,48,95};
    int i,j,loc,len;
    len = N;
    printf("Array: ");
    for(i = 0; i < N; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n Enter loc which you want to delete: \n");
    scanf("%d",&loc);
    if(loc >= N)
    {
        printf("Invalid Location\n");
        return 0;
    }
    for(i = loc; i < N-1; i++)
    {
        ar[i] = ar[i+1];
    }

    len--;
    printf("Updated Array is: ");
    for(i = 0; i < len; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
    return 0;
}