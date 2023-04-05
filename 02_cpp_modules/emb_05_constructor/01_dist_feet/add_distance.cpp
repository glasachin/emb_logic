#include"includes.h"
#include"declarations.h"

void distance1::add_distance(distance1 d1, distance1 d2)
{
    feet = d1.feet + d2.feet;
    inches = d1.inches + d2.inches;
    if(inches >= 12)
    {
        feet += 1;
        inches -= 12;
    }
}