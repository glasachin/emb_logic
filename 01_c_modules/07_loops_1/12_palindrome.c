#include<stdio.h>
int main()
{
    int a,b,rn = 0,in;
    printf("Enter any number: ");
    scanf("%d",&a);
    in = a;
    while(a!=0)
    {
        b = a%10;
        a = a/10;
        rn = rn*10+b;
    }

    if(in == rn)
        printf("Entered number is Palindrome!\n");
    else
        printf("Number is not a Palindrome\n");
    return 0;
}