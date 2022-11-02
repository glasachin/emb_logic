#include"headers.h"
int main()
{
	int n;
	int *arr1;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n);
	reverse_array(arr1,n);
	printf("Reversed array is: \n");
	print_array(arr1, n);
	return 0;	
}
