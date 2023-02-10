#include"headers.h"
int main()
{
	int n;
	int large;
	int *arr1,*uarr, ul = 0;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	printf("Entered array is: \n");
	print_array(arr1, n);
	printf("Unique elements are: \n");
	print_uniques(arr1, n);
	return 0;	
}
