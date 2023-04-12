#include"includes.h"
#include"classes.h"

int main()
{
    Quadratic q1, q2(1.0,4.0,2.0);

    q1.getParameters();
    q1.findRoots();
    q2.findRoots();
    return 0;

}