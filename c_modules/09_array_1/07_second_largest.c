#include<stdio.h>
#define ar_len 5
int main()
{
    int a[ar_len],i,j,lar,sl,sm;
    printf("Enter Array Elements: \n");
    for(i = 0; i < ar_len; i++)
    {
        scanf("%d",&a[i]);
    }

    sm = a[0];
    lar = a[0];
    // sl = a[0];
    sl = 0;
    for(i = 0; i < ar_len; i++)
    {
        if(sm > a[i])
        {
            sm = a[i];
        }
        if((sl < a[i])&&(sl < lar)&&(lar < a[i]))
        {
            sl = lar;
        }
        else if((sl < a[i])&&(lar > a[i]))
        {
            sl = a[i];
        }
        else
        {
            
        }
        if(lar < a[i])
        {
            lar = a[i];
        }
        
    }
    printf("largest: %d\nSecond Largest: %d\nSmalles: %d\n",lar,sl,sm);
    return 0;
}