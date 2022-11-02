#include "array_in.h"

void get_array(int **ar_p, int **n)
{
	int len,i;
	printf("Please Enter length of an array: ");
	scanf("%d",&len);
	*n = &len;
	*ar_p = (int*)malloc(sizeof(int)*(**n));
	printf("Enter array elements: \n");
	for(i = 0; i < **n; i++)
	{
		scanf("%d",*ar_p+i);
	}
	
}

void print_array(int **ar_p, int **n)
{
	int i;
	printf("Entered array is as follows: ");
	for(i = 0; i < **n; i++)
	{
		printf("%d ",*(*ar_p+i));
	}
	printf("\n");
	free(*ar_p);
	*ar_p = NULL;
}
