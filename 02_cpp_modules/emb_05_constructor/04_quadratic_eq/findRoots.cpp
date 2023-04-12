#include"includes.h"
#include"classes.h"

int Quadratic::findRoots()
{
    float r1, r2;
    if ((b*b - 4*a*c) < 0)
        cout<<"Error, Roots will be Imaginary."<<endl;
    else    
    {
        r1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
        r2 = (-b + sqrt(b*b - 4*a*c))/(2*a);
        cout << "one root is: " << r1 << endl;
        cout << "another root is: " << r2 << endl;
    }
    return 0;
}