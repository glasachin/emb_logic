#include"headers.h"

int main()
{
	int n, *arr;
	printf("Enter the number of element in an array: ");
	scanf("%d",&n);
	arr = get_array(n);
	printf("Etered array is: \n");
	print_array(arr, n);
	printf("Reversed array is: \n");
	rev_array(arr, n);
	return 0;

}
