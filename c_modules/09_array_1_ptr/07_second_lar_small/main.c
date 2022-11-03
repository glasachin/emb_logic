#include"headers.h"
int main()
{
	int n,sl,sm;
	int *arr1;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	print_array(arr1, n);
	sm = second_smallest(arr1,n);
	sl = second_largest(arr1,n);
	printf("Second Smallest: %d\n",sm);
	printf("Second Largest: %d\n", sl);	
	return 0;	
}
