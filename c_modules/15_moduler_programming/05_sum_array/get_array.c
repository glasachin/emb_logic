#include"headers.h"

int* get_array(int s)
{
	int i,*arr;
	arr = (int*)malloc(sizeof(int)*LEN(s));
	for(i = 0; i < LEN(s); i++)
	{
		scanf("%d",arr+i);
	}
	return arr;
}
