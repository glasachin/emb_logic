#include"headers.h"

float get_avg(int* arr, int n)
{
	int i;
	float avg=0.0;
	for(i = 0; i < n; i++)
	{
		avg  += (float)*(arr+i)/n;
	}
	return avg;
}
