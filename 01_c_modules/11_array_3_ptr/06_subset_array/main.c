#include"headers.h"
int main()
{
	int n1,n2;
	int *arr1,*arr2;
	printf("Enter the size of array: ");
	scanf("%d",&n1);
	printf("Enter the elements of 1st array: \n");
	arr1 = get_array(n1);
	printf("Enter the size of Sub-set array: ");
	scanf("%d",&n2);
	printf("Enter the elements of Sub-set array: \n");
	arr2 = get_array(n2);
	printf("Entered array is: \n");
	print_array(arr1, n1);
	printf("Entered Sub-set array is: \n");
	print_array(arr2, n2);
	check_subset(arr1,n1,arr2,n2);
	return 0;	
}
