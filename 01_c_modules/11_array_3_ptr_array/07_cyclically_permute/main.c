#include"headers.h"

int main()
{
    int n;
    int **arr;
    arr = get_ptr_array();
    printf("Enter the size of 1st Array: \n");
    scanf("%d",&n);
    printf("Enter Input arrays: \n");
    get_input_array(arr,n,0);
    // do cyclical operation
    copy_array(arr,n,0,1);
    cyc_array(arr,n,1);

    printf("Entered 1st array is : \n");
    print_array(arr,n,0);
    printf("Cyclical array is: \n");
    print_array(arr,n,1);

    
    return 0;
}