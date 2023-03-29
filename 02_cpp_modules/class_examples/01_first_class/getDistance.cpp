#include"includes.h"
#include"declarations.h"

void Distance::getDistance()
{
    cout << __func__ << ":Begin" << endl;
    cout << "Enter the distance in Feet: " ;
    cin >> feet;
    cout << __func__ << ":End" << endl;
}