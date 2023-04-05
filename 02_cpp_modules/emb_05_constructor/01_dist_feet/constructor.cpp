#include"includes.h"
#include"declarations.h"

distance1 :: distance1()
{
    feet = 0;
    inches = 0;
}

distance1 :: distance1(float dis)
{
    feet = int(dis);
    inches = (dis - feet)*12;
}

distance1 :: distance1(int f, int i)
{
    feet = f;
    inches = i;
}

distance1 :: ~distance1()
{
    cout << "Destructor is called" << endl;
}