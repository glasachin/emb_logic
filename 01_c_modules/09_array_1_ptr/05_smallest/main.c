#include"headers.h"
int main()
{
	int n;
	int small;
	int *arr1;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	small = get_small(arr1,n);
	printf("Smallest element in the array is: %d\n",small);
	return 0;	
}
