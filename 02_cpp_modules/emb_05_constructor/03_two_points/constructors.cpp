#include"includes.h"
#include"classes.h"
using namespace std;

point:: point()
{
    x = 0;
    y = 0;
}

point::point(int x1, int y1)
{
    x = x1;
    y = y1;
}

point::point(point & p)
{
    x = p.x;
    y = p.y;
}

point::~point()
{
    cout << "Destructure is called" << endl;
}