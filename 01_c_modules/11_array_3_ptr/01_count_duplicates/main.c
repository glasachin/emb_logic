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
	uarr = get_unique(arr1,n,&ul);
	printf("Unique elements are: \n");
	print_array(uarr, ul);
	print_duplicates(arr1,n,uarr,ul);
	return 0;	
}
