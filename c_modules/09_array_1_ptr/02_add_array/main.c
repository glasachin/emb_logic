#include"headers.h"
int main()
{
	int n;
	int *arr1,*arr2,*arr3;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	printf("Enter the elements of 2nd array: \n");
	arr2 = get_array(n);
	
	arr3 = sum_array(arr1,arr2,n);
	printf("Sum of the two array is: \n");
	print_array(arr3,n);
	return 0;	
	
}
