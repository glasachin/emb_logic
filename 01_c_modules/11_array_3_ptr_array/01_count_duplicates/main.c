#include"headers.h"

int main()
{
    int n;
    int **arr;
    arr = get_ptr_array();
    printf("Enter the size of Input Array: \n");
    scanf("%d",&n);
    printf("Enter Input array: \n");
    get_input_array(arr,n);
    printf("Entered array is : \n");
    print_array(arr,n);
    count_duplicates(arr,n);
    return 0;
}