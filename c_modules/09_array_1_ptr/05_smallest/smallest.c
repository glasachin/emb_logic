#include"headers.h"

int get_small(int *arr, int n)
{
	int i, small = *arr;
	for(i = 1; i < n; i++)
	{
		if(small > *(arr+i))
		       small = *(arr+i);	
	}
	return small;
}
