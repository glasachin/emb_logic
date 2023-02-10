#include"headers.h"

int* sum_array(int *a1, int *a2, int n)
{
	int i, *a3;
	a3 = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++)
	{
		*(a3+i) = *(a1+i)+*(a2+i);
	}
	return a3;
}
