#include"includes.h"
#include"classes.h"

int main()
{
    point p1, p2(10,20);

    p1.getPoint();

    cout << "Distance between points is: " << p1.getDistance(p2) << endl;
    return 0;
}