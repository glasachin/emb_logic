#include<stdio.h>

int print_even(int,int);
int num = 0;
int main()
{
    int start, end;
    printf("Enter start of the range: ");
    scanf("%d",&start);
    printf("Enter end of the range: ");
    scanf("%d",&end);
    num = start;
    print_even(start,end);
    printf("\n");
    return 0;
}

int print_even(int a, int b)
{
    if(num > b)
        return 0;
    
    if(num%2 == 0)
        printf("%d ", num);
    num++;
    return print_even(a,b);

}