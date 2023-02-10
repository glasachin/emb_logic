#include"headers.h"
int main()
{
	int n;
	int large;
	int *arr1,*arr2, *arr3;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	printf("Enter the elements of 2nd array: \n");
	arr2 = get_array(n);
	printf("Entered 1st array is: \n");
	print_array(arr1, n);
	printf("Entered 2nd array is: \n");
	print_array(arr2, n);
	arr3 = merge_array(arr1, arr2, n);
	printf("Merged and Sorted array is: \n");
	print_array(arr3, 2*n);
	return 0;	
}
