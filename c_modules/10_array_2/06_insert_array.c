#include<stdio.h>
#define N 5
int main()
{
    int ar[N+3] = {1,3,5,2,8};
    int i,j,val,loc,len;
    len = N;
    printf("Array: ");
    for(i = 0; i < N; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n Enter loc and value to be inserted: \n");
    scanf("%d%d",&loc,&val);
    if(loc > N)
    {
        printf("Invalid Location\n");
        return 0;
    }
    for(i = N; i > loc; i--)
    {
        ar[i] = ar[i-1];
    }
    ar[loc] = val;
    len++;
    printf("Updated Array is: ");
    for(i = 0; i < len; i++)
    {
        printf("%d ",ar[i]);
    }
    printf("\n");
    return 0;
}