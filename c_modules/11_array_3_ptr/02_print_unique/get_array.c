#include"headers.h"

int* get_array(int n)
{
	int i, *arr;
	arr = (int*)malloc(sizeof(int)*n);
	for(i = 0; i < n; i++)
		scanf("%d",arr+i);
	return arr;
}
