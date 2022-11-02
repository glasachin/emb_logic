#include "functions.h"
#include "globals.h"
int* get_input()
{
	printf("Enter any number: ");
	scanf("%d",&n);
	return &n;
}

int* compute_fact(int *p)
{
	while(*p > 1)
	{
		val *= *p;
	       *p -= 1;	
	}
	return &val; 
}

void print_fact(int *p)
{
	printf("Factorial is %d \n", *p);
}
