#include "headers.h"
int main()
{
	int n, *array;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter array elements: \n");
	array = get_array(n);
	printf("Finding the sum of array: \n");
	print_arr(array, n);
	find_sum(array,n);
	return 0;
}
