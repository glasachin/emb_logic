#include"headers.h"

int main()
{
    int n,pl;
    int **arr;
    arr = get_ptr_array();
    printf("Enter the size of 1st Array: \n");
    scanf("%d",&n);
    printf("Enter Input arrays: \n");
    get_input_array(arr,n,0);
    printf("Entered 1st array is : \n");
    print_array(arr,n,0);
    
    find_prime(*(arr+0),n,arr+1,&pl);
    printf("Merged and sorted array is: \n");
    print_array(arr,pl,1);
    return 0;
}