#include"includes.h"
#include"declarations.h"

void Distance::displayDistance()
{
    cout << __func__ << ":Begin" << endl;

    inches = 12*feet;
    cout << feet << " Feet Equls to " << inches << " inches" << endl;

    cout <<__func__<<":End" << endl;
}