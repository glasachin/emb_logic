#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter the sides of a Triangle: \n");
    scanf("%d%d%d",&a,&b,&c);
    if((a==b) && (b==c))
    {
        printf("Triangle is Equilateral\n");
    }
    else if((a==b) || (a==c) || (b==c))
    {
        printf("Triangle is Isosceles\n");
    }
    else
        printf("Triangle is Scalene\n");

    return 0; 
}