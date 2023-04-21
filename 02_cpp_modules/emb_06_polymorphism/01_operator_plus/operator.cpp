#include"includes.h"
#include"classes.h"

circle circle::operator + (circle c1)
{
    circle c;
    c.rad = rad + c1.rad;
    return c;
}