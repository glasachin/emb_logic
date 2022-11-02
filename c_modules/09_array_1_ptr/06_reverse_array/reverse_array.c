#include"headers.h"
void reverse_array(int* arr,int n)
{
    int i,j = n - 1;
    int temp;
    for(i = 0; i < n/2; i++)
    {
        temp = *(arr+i);
        *(arr+i) = *(arr+j);
        *(arr+j) = temp;
        j--;
    }
}