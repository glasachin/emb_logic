#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    printf("Enter first side: ");
    scanf("%f",&a);
    printf("Enter Second side: ");
    scanf("%f",&b);
    c = sqrt(pow(a,2)+pow(b,2));
    printf("Hypotenuse is %0.2f",c);
    return 0;
}