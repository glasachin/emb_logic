#include"includes.h"
#include"declarations.h"

int main()
{
    cout << __func__ <<":Begin" << endl;
    Distance dA;

    // get the values
    dA.getDistance();

    // display the values
    dA.displayDistance();

    return(0);
}