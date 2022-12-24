#include<stdio.h>
int mul(int a, int b, int c)
{
	return a*b*c;
}

void main()
{
	int (*fptr)(int, int, int);
	fptr = mul;
	printf("Mul is: %d\n",(*fptr)(3,2,5));
	printf("Mul is: %d\n",fptr(3,2,5));
	
}

