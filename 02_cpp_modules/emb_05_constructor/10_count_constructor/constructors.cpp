#include"includes.h"
#include"classes.h"
#include"globals.h"
int obj_count;

funobj::funobj()
{
    x = 0;
    y = 0;
    obj_count++;
}
funobj::funobj(int a, int b)
{
    x = a;
    y = b;
    obj_count++;
}
funobj::~funobj()
{
    obj_count--;
}