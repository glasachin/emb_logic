#include"includes.h"
#include"classes.h"

int main()
{
    dismeter d1, d2(10,50);
    disfeet d3, d4(5,6);

    d1 = d4;
    d3 = d2;

    d1.displayDismeter();
    d3.displayDisfeet();
    
    return 0;
}