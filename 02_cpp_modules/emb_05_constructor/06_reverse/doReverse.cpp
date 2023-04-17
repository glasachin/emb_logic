#include"includes.h"
#include"classes.h"

int reverse::doReverse()
{
    int strlen = 0;
    char b[10];
    int i,j;
    for(i = 0; a[i] != '\0'; i++)
    {
        strlen += 1;
    }

    for(i = strlen-1; i >= 0; i--)
    {
        b[j] = a[i];
        j++;
    }
    b[j] = '\0';

    cout<<"Reverse String: "<<b<<endl;
    return 0;
}