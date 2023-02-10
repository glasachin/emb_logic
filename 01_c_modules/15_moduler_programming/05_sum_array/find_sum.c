#include"headers.h"

void find_sum(int* arr, int n)
{
	int i,sum=0;
	for(i = 0; i < LEN(n); i++)
	{
		sum += *(arr+i);
	}
	printf("Sum of the array is %d\n",sum);
}
