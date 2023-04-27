#include"includes.h"
#include"classes.h"

int main()
{
    circle c1(3), c2(5);

    circle c3 = c1+c2;

    c3.displayCircle();
    return 0;
}