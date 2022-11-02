#include"headers.h"

void rev_array(int* arr, int s)
{
	int i = 0;
	for(i = LEN(s)-1; i >= 0; i--)
	{
		printf("%d ",*(arr+i));
	}	
	printf("\n");
}
