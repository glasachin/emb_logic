#include<stdio.h>
int main()
{
    int a,i,nd;
    printf("Enter any number: ");
    scanf("%d",&a);
    nd = 0;
    if(a != 0)
    {
        while(a!=0)
        {
            nd+=1;
            a=a/10;
        }
    }
    else
    {
        nd = 1;
    }
    
    printf("There are %d digits\n",nd);
    return 0;
}