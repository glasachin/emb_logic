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
	printf("Entered array is: \n");
	print_array(arr1, n);
	printf("Prime elements in array are: \n");
	find_primes(arr1,n);
	return 0;	
}
