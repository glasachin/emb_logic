#include"headers.h"

int main()
{
    int n,el,ol;
    int **arr;
    arr = get_ptr_array();
    printf("Enter the size of Array: \n");
    scanf("%d",&n);
    printf("Enter the elements of array: \n");
    get_input_array(arr,n,0);
    printf("Entered 1st array is : \n");
    print_array(arr,n,0);

    find_odd_even(arr,n,&el,&ol);

    printf("even elements of the array are: \n");
    print_array(arr,el,1);
    printf("even elements of the array are: \n");
    print_array(arr,ol,2);

    return 0;

}