#include"includes.h"
#include"classes.h"

rectangle rectangle::operator + (rectangle c1)
{
    rectangle c;
    c.length = length + c1.length;
    c.width = width + c1.width;
    return c;
}