#include"headers.h"

int get_large(int *arr, int n)
{
	int i, large = *arr;
	for(i = 1; i < n; i++)
	{
		if(large < *(arr+i))
		       large = *(arr+i);	
	}
	return large;
}
