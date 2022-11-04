#include"headers.h"
int main()
{
	int n;
	int *arr1;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	printf("Entered array is: \n");
	print_array(arr1, n);
	printf("Sum of array elements is: %d\n",sum_array(arr1,n));
	printf("Avg of array elements is: %0.2f\n",avg_array(arr1,n));

	return 0;	
}
