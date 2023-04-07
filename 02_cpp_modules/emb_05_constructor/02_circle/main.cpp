#include"includes.h"
#include"declarations.h"

int main()
{
    Circle c1, c2(2.0);

    c1.getRadius();
    cout << "c1 area is: " << endl;
    c1.calArea(); 
    cout << "c1 parimeter is: " << endl;
    c1.calParimeter();

    cout << "c2 area is: " << endl;
    c2.calArea(); 
    cout << "c2 parimeter is: " << endl;
    c2.calParimeter();

    return 0;
}