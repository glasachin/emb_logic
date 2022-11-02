#include"headers.h"

void print_arr(int *arr,int s)
{
	int i;
	printf("Entered array is: ");
	for(i = 0; i < LEN(s); i++)
	{
		printf("%d ",*(arr+i));
	}
	printf("\n");
}
