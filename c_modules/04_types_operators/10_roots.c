#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    float r1, r2;
    printf("Note: This program will find the real roots only.\n");
    printf("Enter the value of a: ");
    scanf("%f",&a);
    printf("Enter the value of b: ");
    scanf("%f",&b);
    printf("Enter the value of c: ");
    scanf("%f",&c);

    r1 = (b*b - 4*a*c) >= 0 ? ((-b + sqrt(b*b - 4*a*c))/(2*a)) : 0;
    r2 = (b*b - 4*a*c) >= 0 ? ((-b - sqrt(b*b - 4*a*c))/(2*a)) : 0;
    printf("Root 1: %0.2f and Root 2: %0.2f\n",r1,r2);
    return 0;
}