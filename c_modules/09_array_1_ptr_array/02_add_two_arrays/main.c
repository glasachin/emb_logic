#include"headers.h"

int main()
{
    int n,i;
    int **arr;
    arr = get_ptr_array();
    printf("Enter the size of Array: \n");
    scanf("%d",&n);
    printf("Enter the elements of 1st array: \n");
    get_input_array(arr,n,0);
    printf("Enter the elements of 2nd array: \n");
    get_input_array(arr,n,1);
    printf("Entered 1st array is : \n");
    print_array(arr,n,0);
    printf("Entered 2nd array is: \n");
    print_array(arr,n,1);

    add_2_arrays(arr,0,1,2,n);

    printf("Sum of two arrays is: \n");

    for(i = 0; i < n; i++)
    {
        printf("%d + %d = %d\n",*(*(arr+0)+i),*(*(arr+1)+i),*(*(arr+2)+i));
    } 
    return 0;
}