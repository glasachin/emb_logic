#include<stdio.h>
#include<stdlib.h>
int main()
{
    float a, b, c;
    char oper;
    printf("Enter Your Choice: \n");
    printf("+: To add two numbers\n");
    printf("-: To subtract two numbers\n");
    printf("*: To multipy two numbers\n");
    printf("/: To divice two number\n");
    printf("%%: To get get the Reainder\n");
    printf("x: To exit the program\n");
    scanf("%c",&oper);
    switch(oper)
    {
        case '+':
            printf("Enter 1st number: ");
            scanf("%f",&a);
            printf("Enter 2nd number: ");
            scanf("%f",&b);
            c = a + b;
            printf("Sum of %0.2f and %0.2f is %0.2f\n",a,b,c);
            break;
        case '-':
            printf("Enter 1st number: ");
            scanf("%f",&a);
            printf("Enter 2nd number: ");
            scanf("%f",&b);
            c = a - b;
            printf("Subtraction of %0.2f and %0.2f is %0.2f\n",a,b,c);
            break;
        case '*':
            printf("Enter 1st number: ");
            scanf("%f",&a);
            printf("Enter 2nd number: ");
            scanf("%f",&b);
            c = a * b;
            printf("Multiplication of %0.2f and %0.2f is %0.2f\n",a,b,c);
            break;
        case '/':
            printf("Enter 1st number: ");
            scanf("%f",&a);
            printf("Enter 2nd number: ");
            scanf("%f",&b);
            c = a / b;
            printf("Division of %0.2f and %0.2f is %0.2f\n",a,b,c);
            break;
        case '%':
            printf("Enter 1st number: ");
            scanf("%f",&a);
            printf("Enter 2nd number: ");
            scanf("%f",&b);
            c = (int)a % (int)b;
            printf("Remainder of %0.2f and %0.2f is %0.2f\n",a,b,c);
            break;
        case 'x':
            exit(0);
        default:
            printf("Wrong Choice!\n");
            break;
    }
    return 0;
}