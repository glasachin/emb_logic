#include"headers.h"
int main()
{
	int n;
	float avg;
	int *arr1;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	avg = get_avg(arr1,n);
	printf("Average of the array is: %0.2f\n",avg);
	return 0;	
}
