#include"headers.h"

void print_array(int* arr, int s)
{
	int i;
	for(i = 0; i < LEN(s); i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}
