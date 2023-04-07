#include"includes.h"
#include"declarations.h"

Circle :: Circle()
{
    r = 0.0;
    area = 0.0;
    perimeter = 0.0;
}

Circle :: Circle(float rad)
{
    r = rad;
    area = 0.0;
    perimeter = 0.0;
}

Circle :: ~Circle()
{
    cout<<"Destructor is called." << endl;
}

