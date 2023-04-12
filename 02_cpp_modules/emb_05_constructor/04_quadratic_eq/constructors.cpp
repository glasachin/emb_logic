#include"includes.h"
#include"classes.h"

Quadratic::Quadratic(float x, float y, float z)
{
    a = x;
    b = y;
    c = z;
}

Quadratic::~Quadratic()
{
    cout<<"Destructor is called" << endl;
}