#include<stdio.h>
int main()
{
    int i = 0, n = 5, lar;
    int a[10];
    printf("Enter any %d Numbers \n",n);
    while(i < n)
    {
        scanf("%d",&a[i]);
        i++;
    }
    lar = a[0];
    for(i = 0; i < n; i++)
    {
        if(lar > a[i])
            lar = a[i];
    }
    printf("Smallest number is: %d",lar);
    return 0;
}