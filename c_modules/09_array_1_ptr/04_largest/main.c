#include"headers.h"
int main()
{
	int n;
	int large;
	int *arr1;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	large = get_large(arr1,n);
	printf("largest element in the array is: %d\n",large);
	return 0;	
}
