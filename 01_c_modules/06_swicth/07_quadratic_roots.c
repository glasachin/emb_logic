#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    float r1, r2;
    printf("Enter the values of a,b,c: ");
    scanf("%f%f%f",&a,&b,&c);
    switch((int)((b*b-4*a*c) >= 0))
    {
        case 1:
            r1 = (-b + sqrt(b*b-4*a*c))/(2*a);
            r2 = (-b - sqrt(b*b-4*a*c))/(2*a);
            printf("%0.2f and %0.2f are the roots of the queation\n",r1,r2);
            break;
        default:
            printf("There will no real roots\n");
            break;
    }
    return 0;
}