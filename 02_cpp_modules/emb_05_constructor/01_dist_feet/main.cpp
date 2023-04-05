#include"includes.h"
#include"declarations.h"

int main()
{
    distance1 d1(10.5), d2(10,6), d3;

    d3.add_distance(d1,d2);
    d3.display();

    return 0;
}