#include"headers.h"

int main()
{
    int row = 0, col = 0;
    char *arr;
    get2Darray(&arr,&row,&col);
    fill2Darray(arr,&row,&col);
    print2Darray(arr,&row,&col);
    return 0;
}