#include"headers.h"

int main()
{
    int n1,n2;
    int **arr;
    arr = get_ptr_array();
    printf("Enter the size of 1st Array: \n");
    scanf("%d",&n1);
    printf("Enter Input arrays: \n");
    get_input_array(arr,n1,0);
    printf("Enter the size of 1st Array: \n");
    scanf("%d",&n2);
    printf("Enter the 2nd array: \n");
    get_input_array(arr,n2,1);
    printf("Entered 1st array is : \n");
    print_array(arr,n1,0);
    printf("Entered 2nd array is: \n");
    print_array(arr,n2,1);
    
    check_subset(*(arr+0),n1,*(arr+1),n2);
    
    return 0;
}