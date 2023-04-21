#include"includes.h"
#include"classes.h"

int main()
{
    rectangle c1(3,4), c2(5,6);

    rectangle c3 = c1+c2;

    c3.displayRectangle();
    return 0;
}