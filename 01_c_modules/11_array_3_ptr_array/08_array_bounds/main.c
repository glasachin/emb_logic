#include"headers.h"

int main()
{
    int n;
    int **arr;
    arr = get_ptr_array();
    printf("Enter the size of 1st Array: \n");
    scanf("%d",&n);
    printf("Enter Input arrays: \n");
    get_input_array(arr,n+8,0);
    
    printf("Entered 1st array is : \n");
    print_array(arr,n+12,0);
        
    return 0;
}